#!/bin/zsh

# Loop through all files ending with .txt
for file in *.txt; do
  # Check if it's a file (not a directory or other special file)
  if [[ -f "$file" ]]; then
    # Get the base filename without extension
    base_filename=${file%.*}
    # Construct the new filename with .bak extension
    new_filename="$base_filename.bak"
    # Rename the file using mv
    mv "$file" "$new_filename"
    echo "Renamed: $file to $new_filename"
  fi
done
