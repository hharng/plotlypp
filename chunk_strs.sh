python3 -c '
import sys

# 1. Read all bytes
d = sys.stdin.buffer.read()

# 2. Chunk size (Source bytes)
CHUNK = 4096

output = []
# Standard delimiter "p" -> R"p(...)p"
delim = b"p"
delim_safe = b"safe"

# Split by 0x1A byte
segments = d.split(b"\x1a")

for i, segment in enumerate(segments):
	if segment:
		for j in range(0, len(segment), CHUNK):
		    chunk = d[j:j+CHUNK]
		    # Safety Check: Does the chunk contain our closing delimiter?
		    if b")" + delim + b"\"" in chunk:
		        if b")" + delim_safe + b"\"" in chunk:
		        	raise ValueError("Collision with default and fallback delimiters!")
		        output.append(b"R\"" + safe_delim + b"(" + chunk + b")" + safe_delim + b"\"")
		    else:
		        # Standard case
		        output.append(b"R\"" + delim + b"(" + chunk + b")" + delim + b"\"")
    # Add the escaped byte between segments
	if i < len(segments) - 1:
		output.append(b"\"\\x1a\"")
# 3. Write lines joined by newlines
sys.stdout.buffer.write(b"\n".join(output))
' < generator/plotly.min.js > embedded_assets_raw_4096.txt
