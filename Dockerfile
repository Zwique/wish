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

# Run the wish binary
CMD ["nc", "-lvnp", "1337", "-e", "/wish"]
