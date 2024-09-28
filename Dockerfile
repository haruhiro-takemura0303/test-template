# Specify the base image
FROM ubuntu:20.04

# Set environment variable
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    git \
    && apt-get clean

# Install Google Test from source
RUN git clone https://github.com/google/googletest.git /usr/src/googletest && \
    cd /usr/src/googletest && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    cp -r ../googletest/include/* /usr/local/include/ && \
    cp -r ../googlemock/include/* /usr/local/include/ && \
    cp -r lib/* /usr/local/lib/ && \
    ldconfig

# Mount the application source code
VOLUME /app

# Set the working directory
WORKDIR /app

# Set the default command
CMD ["/bin/bash"]
