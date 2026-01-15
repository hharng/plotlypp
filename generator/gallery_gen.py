import os
import json
import plotly.graph_objects as go

# --- CONFIG ---
INPUT_DIR = os.path.join(os.path.dirname(__file__), "../examples/output/json")
OUTPUT_DIR = os.path.join(os.path.dirname(__file__), "../examples/output/png_exports")
WIDTH, HEIGHT, SCALE = 1000, 800, 2
COLS = 5

os.makedirs(OUTPUT_DIR, exist_ok=True)

# 2. Process Files
json_files = sorted([f for f in os.listdir(INPUT_DIR) if f.endswith(".json")])
html_output = ['<table width="100%" cellspacing="0" cellpadding="0" style="border-collapse: collapse;">']

for i, filename in enumerate(json_files):
    base_name = os.path.splitext(filename)[0]
    png_name = f"{base_name}.png"
    html_link = f"https://jimmyorourke.github.io/plotlypp/examples/output/{base_name}.html"

    # print(f"[{i+1}/{len(json_files)}] Rendering {png_name}...")

    # with open(os.path.join(INPUT_DIR, filename), "r") as f:
    #     fig_data = json.load(f)

    # fig = go.Figure(fig_data)

    # # --- THUMBNAIL OPTIMIZATION ---
    # # 1. Apply global font (best for 2D)
    # fig.update_layout(
    #     font=dict(size=26), # High readability
    #     title=dict(text=base_name, font=dict(size=34)),
    #     margin=dict(t=100, b=60, l=60, r=60),
    #     template="plotly_white", # Cleanest look for READMEs and more like the JS default.
    #     width=WIDTH,
    #     height=HEIGHT
    # )
    # # The default colorscale is also different between JS and Python, with JS using "RdBu" nad Python using "Viridis".
    # # I actually prefer the Python version, so let's keep it even though it will make the thumbnails look different.

    # # 2. Check if the plot has a 3D "scene" and shrink its fonts since the axes numbers end up super bloated.
    # # Look for 'scene' keys in the layout which indicate a 3D plot
    # if any(k.startswith('scene') for k in fig.layout):
    #     fig.update_scenes(
    #         xaxis=dict(tickfont=dict(size=14), title_font=dict(size=16)),
    #         yaxis=dict(tickfont=dict(size=14), title_font=dict(size=16)),
    #         zaxis=dict(tickfont=dict(size=14), title_font=dict(size=16))
    #     )

    # # Export PNG
    # png_path = os.path.join(OUTPUT_DIR, f"{os.path.splitext(filename)[0]}.png")
    # fig.write_image(png_path, scale=SCALE, engine="kaleido")
    # print(f"[{i+1}/{len(json_files)}] Rendered {png_path}")


    # --- TABLE CONSTRUCTION WITH UI STYLING ---
    if i % COLS == 0: html_output.append("  <tr>")

    # style="border-radius: 8px" adds the rounded corners
    # style="border: 1px solid #d0d7de" adds a subtle gray border (GitHub style)
    cell = f'''    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="{html_link}"><img src="./examples/output/png_exports/{png_name}" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>'''
    html_output.append(cell)

    if i % COLS == (COLS - 1) or i == len(json_files) - 1:
        if i == len(json_files) - 1 and (i + 1) % COLS != 0:
            for _ in range(COLS - ((i + 1) % COLS)):
                html_output.append('    <td width="20%"></td>')
        html_output.append("  </tr>")

html_output.append("</table>")

with open("README_GALLERY.md", "w") as f:
    f.write("\n".join(html_output))

print(f"\nDone! Your gallery is ready in README_GALLERY.md.")
