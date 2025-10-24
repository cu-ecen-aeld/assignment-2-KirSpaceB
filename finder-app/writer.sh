#!/bin/bash
set -euo pipefail

if [ $# -ne 2 ]; then
  echo "Usage: $0 <writefile> <writestr>"
  exit 1
fi

writefile=$1
writestr=$2

# Ensure parent directory exists
mkdir -p "$(dirname "$writefile")" || {
  echo "Error: could not create path for $writefile"
  exit 1
}

# overwrite
if ! printf "%s\n" "$writestr" > "$writefile"; then
  echo "Error: could not write to $writefile"
  exit 1
fi

