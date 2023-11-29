FROM cpp-with-gtest-base:0.3.0 AS build
LABEL stage=builder
WORKDIR /build_dir

COPY ./ ./

RUN cmake . && cmake --build . && ./src/aoc_test

FROM gcc:13.2.0

WORKDIR /opt/other

COPY --from=build /build_dir/src/aoc ./
COPY inputs inputs

ENTRYPOINT ["./aoc"]
