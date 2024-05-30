#!/bin/zsh

# Loop through files in the current directory
for file in *; do
  # Get file size using stat -c %s
  size=$(stat -c %s "$file")
  # Print filename and size
  echo "$file ($size bytes)"
done
