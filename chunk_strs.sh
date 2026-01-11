python3 -c '
import sys

# 1. Read all bytes
d = sys.stdin.buffer.read()

# 2. Chunk size (Source bytes)
CHUNK = 4096

output = []
# Standard delimiter "p" -> R"p(...)p"
delim = b"p"

for i in range(0, len(d), CHUNK):
    chunk = d[i:i+CHUNK]

    # Safety Check: Does the chunk contain our closing delimiter?
    # If the file contains ")p"", we must not use "p" as the delimiter.
    if b")" + delim + b"\"" in chunk:
        # Fallback to "safe" -> R"safe(...)safe"
        output.append(b"R\"safe(" + chunk + b")safe\"")
    else:
        # Standard case
        output.append(b"R\"" + delim + b"(" + chunk + b")" + delim + b"\"")

# 3. Write lines joined by newlines
sys.stdout.buffer.write(b"\n".join(output))
' < generator/plotly.min.js > embedded_assets_raw_4096.txt
