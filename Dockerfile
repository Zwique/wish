FROM debian:bullseye

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    netcat \
    && rm -rf /var/lib/apt/lists/*

# Add the wish source code
COPY ./wish /wish
COPY ./flag.txt /flag.txt

# Set the working directory
WORKDIR /wish

# Expose the port you want to listen to
EXPOSE 1337

# Use a shell to run the wish binary
CMD ["sh", "-c", "nc -lvnp 1337 < /wish"]
