#!/bin/bash

EXECUTABLE="../.././cub3D"

MAP_DIR="../../map/error"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

TEMP_FILE=$(mktemp)
trap 'rm -f $TEMP_FILE' EXIT

echo -e "${YELLOW}Starting e2e ErrorCaseTest ...${NC}"
echo "Executable: $EXECUTABLE"
echo "Testing directory: $MAP_DIR"
echo "--------------------------------------"

find "$MAP_DIR" -name "*.cub" > $TEMP_FILE
echo "$MAP_DIR/DOES_NOT_EXIST.cub" >> $TEMP_FILE

while read file; do
    echo -e "Running: ${GREEN}$EXECUTABLE $file${NC}"
        OUTPUT=$($EXECUTABLE "$file" 2>&1)
        RETURN_CODE=$?
        
        if [ $RETURN_CODE -eq 0 ]; then
            echo -e "${GREEN}Success: ${NC}$file passed the test."
        else
            echo -e "${RED}Error in file: ${NC}$file"
            echo -e "${RED}Output: ${NC}"
            echo "$OUTPUT" | sed "s/^/    /"
        fi
    echo "--------------------------------------"
done < "$TEMP_FILE"

echo -e "${YELLOW}All tests completed.${NC}"