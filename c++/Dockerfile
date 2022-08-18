FROM cpp-with-gtest-base:0.1.0 AS build
LABEL stage=builder
WORKDIR /build_dir

COPY ./ ./

RUN cmake . && cmake --build .

FROM ubuntu:bionic

WORKDIR /opt/other

COPY --from=build /build_dir/src/aoc ./
COPY inputs inputs

ENTRYPOINT ["./aoc"]
