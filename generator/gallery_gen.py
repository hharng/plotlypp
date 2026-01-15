import os
import json
import plotly.graph_objects as go

# --- CONFIG ---
INPUT_DIR = os.path.join(os.path.dirname(__file__), "../examples/output")
OUTPUT_DIR = os.path.join(os.path.dirname(__file__), "../examples/output/png_exports")
WIDTH, HEIGHT, SCALE = 1000, 800, 2
COLS = 5

os.makedirs(OUTPUT_DIR, exist_ok=True)

# 2. Process Files
json_files = sorted([f for f in os.listdir(INPUT_DIR) if f.endswith(".json")])
html_output = ["<table>"]

for i, filename in enumerate(json_files):
    base_name = os.path.splitext(filename)[0]
    png_name = f"{base_name}.png"
    html_link = f"{base_name}.html"

    print(f"[{i+1}/{len(json_files)}] Rendering {png_name}...")

    with open(os.path.join(INPUT_DIR, filename), "r") as f:
        fig_data = json.load(f)

    fig = go.Figure(fig_data)

    # --- THUMBNAIL OPTIMIZATION ---
    fig.update_layout(
        font=dict(size=26), # High readability
        title=dict(text=os.path.splitext(filename)[0], font=dict(size=34)),
        margin=dict(t=100, b=60, l=60, r=60),
        template="plotly_white", # Cleanest look for READMEs
        width=WIDTH,
        height=HEIGHT
    )

    # Export PNG
    png_path = os.path.join(OUTPUT_DIR, f"{os.path.splitext(filename)[0]}.png")
    fig.write_image(png_path, scale=SCALE, engine="kaleido")
    print(f"[{i+1}/{len(json_files)}] Rendered {png_path}")


    # --- TABLE CONSTRUCTION WITH UI STYLING ---
    if i % COLS == 0: html_output.append("  <tr>")

    # style="border-radius: 8px" adds the rounded corners
    # style="border: 1px solid #d0d7de" adds a subtle gray border (GitHub style)
    cell = f'''    <td align="center" width="20%" valign="top" style="padding: 10px;">
      <a href="./{html_link}">
        <img src="./png_exports/{png_name}"
             width="100%"
             style="border-radius: 8px; border: 1px solid #d0d7de; box-shadow: 0 1px 3px rgba(0,0,0,0.1);" />
      </a>
      <br />
      <p style="margin-top: 8px;"><sub><b>{base_name}</b></sub></p>
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
