#!/bin/bash

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
PURPLE="\033[0;35m"
YELLOW="\033[0;33m"
NC="\033[0m" # No Color

run_command() {
    INPUT="$1"
    echo -e "${PURPLE}Input: ${NC}"
    echo -e "$INPUT"

    OUTPUT=$(valgrind -q \
        --leak-check=full \
        --show-leak-kinds=all \
        --errors-for-leak-kinds=all \
        --track-fds=yes \
        --error-exitcode=123 \
        ./cub3D "$INPUT" 2>&1)

    EXIT_STATUS=$?

    echo -e "${PURPLE}Output: ${NC}"
    echo -e "$OUTPUT"

    if [ $EXIT_STATUS -eq 123 ]; then
        echo -e "${PURPLE}Valgrind: ${RED}KO${NC}"
    else
        echo -e "${PURPLE}Valgrind: ${GREEN}OK${NC}"
    fi

    echo -e "${GREEN}--------------------------------------------------------------------${NC}"
}

run_tests() {
    echo -e "\n\n${YELLOW} Running bad config files ${NC}"
    echo -e "${YELLOW} ========================== ${NC}\n\n"

    for file in maps/bad/*.cub maps/bad/*.buc maps/bad/filetype_missing; do
        if [ -f "$file" ]; then
            run_command "$file"
        else
            echo -e "${RED}Warning: File not found - $file${NC}"
        fi
    done

    echo -e "\n\n${YELLOW} Running good config files ${NC}"
    echo -e "${YELLOW} =========================== ${NC}\n\n"

    for file in maps/good/*.cub; do
        if [ -f "$file" ]; then
            run_command "$file"
        else
            echo -e "${RED}Warning: File not found - $file${NC}"
        fi
    done
}

run_tests
