#!/usr/bin/env bash

set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

function check_log() {
    LOG=$( { ${1}; } 2>&1 )
    STATUS=$?
    echo "$LOG"
    if echo "$LOG" | grep -q -E "${2}"
    then
        exit 1
    fi

    if [ $STATUS -ne 0 ]
    then
        exit $STATUS
    fi
}

print_header "RUN cppcheck"
check_log "cppcheck project --enable=warning --inconclusive --error-exitcode=0 -I project/include --suppress=missingIncludeSystem" "\(information\)"

print_header "RUN clang-tidy"
check_log "clang-tidy project/src/*.c -header-filter=.* -extra-arg=-std=gnu99 -- -Iproject/include" "Error (?:reading|while processing)"

#print_header "RUN cppcheck"
#check_log "cppcheck --verbose  --error-exitcode=0 project/src/*.c project/include/*"

#print_header "RUN cpplint"
#check_log "cpplint --extensions=c project/include/* project/src/*" "Can't open for reading"

print_header "SUCCESS"