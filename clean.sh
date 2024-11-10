#!/bin/bash

# Define a list of extensions to be considered as executables
EXCLUDE_EXTENSIONS=("sh" "md" "txt" "jpg" "png" "git" "json" "cpp" "h" "py")

# Loop through each extension type
for ext in out exe bin o a so dll; do
  find . -type f -name "*.$ext" -and ! -path "./.git/*" -exec rm -v {} \;
done

echo "Specified executables in '.' and its subdirectories, excluding shell scripts and .git directory, have been removed."
