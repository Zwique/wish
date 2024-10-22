# Base image
FROM debian:bullseye

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    netcat \
    && rm -rf /var/lib/apt/lists/*

# Copy challenge and flag files into the container
COPY ./wish.c /wish.c
COPY ./flag.txt /flag.txt

# Compile the challenge
RUN gcc /wish.c -o /wish

# Expose the port you want to listen on (use 9999 or any other port)
EXPOSE 8080

# Use netcat to listen on the specified port and run the wish binary
CMD ["nc", "-l", "-p", "9999", "-e", "/wish"]
