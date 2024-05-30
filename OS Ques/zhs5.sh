#!/bin/zsh

# Get the current directory name
current_dir=$(pwd)
# Get the timestamp for the backup
timestamp=$(date +%Y-%m-%d_%H-%M-%S)
# Create the backup directory name with timestamp
backup_dir="$current_dir-backup-$timestamp"

# Check if backup directory exists
if [[ -d "$backup_dir" ]]; then
  echo "Backup directory already exists: $backup_dir"
  exit 1  # Exit with an error code if backup directory exists
fi

# Create the backup directory using mkdir
mkdir "$backup_dir"
echo "Created backup directory: $backup_dir"

# Archive the current directory using tar (adjust options as needed)
tar -cvf "$backup_dir.tar" "$current_dir"
echo "Created archive: $backup_dir.tar"
