FROM cpp-with-gtest-base:0.1.0 AS build
LABEL stage=builder
WORKDIR /src

COPY ./ ./

RUN cmake . && cmake --build . && ./aoc_test

FROM ubuntu:bionic

WORKDIR /opt/other

COPY --from=build /src/aoc ./
COPY inputs/ ./inputs/

ENTRYPOINT ["./aoc"]
