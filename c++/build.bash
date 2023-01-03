#!/usr/bin/bash

FULL_SCRIPT_PATH="$(readlink -f "${BASH_SOURCE[0]}")"
SCRIPT_DIR="$(dirname "${FULL_SCRIPT_PATH}")"

VERSION="$(grep "aoc VERSION" "${SCRIPT_DIR}/CMakeLists.txt" | grep -oE "(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)")"


if [ "${BASH_SOURCE[0]}" == "$0" ]; then
    echo "Building version: ${VERSION}"

    pushd "${SCRIPT_DIR}" || exit 1
    docker build -t "aoc:${VERSION}" .
    popd || exit 1
fi
