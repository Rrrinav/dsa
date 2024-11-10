#!/bin/bash

# Define extensions to exclude
EXCLUDE_EXTENSIONS=("sh" "md" "txt" "jpg" "png" "git" "json" "cpp" "h" "py")

# Build the exclude pattern for the find command
EXCLUDE_PATTERN=""
for ext in "${EXCLUDE_EXTENSIONS[@]}"; do
  EXCLUDE_PATTERN="$EXCLUDE_PATTERN -not -name '*.$ext'"
done

# Get the script's own filename to exclude it
SCRIPT_NAME="$(basename "$0")"

# Find and delete executable files without specified extensions, ignoring .git and excluding this script
echo "Searching and deleting executables without extensions and excluded types..."
find . -type f -executable $EXCLUDE_PATTERN -not -name "$SCRIPT_NAME" -not -path "./.git/*" -exec rm -v {} \;

echo "Executable files without extensions in '.' and its subdirectories, excluding specified types, have been removed."
