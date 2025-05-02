
# Minitalk

## Project Overview

**Minitalk** is a small UNIX communication project that demonstrates inter-process communication using only UNIX **signals** (`SIGUSR1` and `SIGUSR2`). The goal is to create a client-server communication model where the client sends a string message to the server, one bit at a time, via signals.

This project was developed as part of the 42 Istanbul curriculum.

Key learning outcomes include:

- Mastering **UNIX signals** and signal handlers
- Bit-level data encoding and transmission
- Building a **fully asynchronous** client-server system
- Managing memory and avoiding race conditions in C

---

## How It Works

- The **server** process is started first and prints its **PID** to the console.
- The **client** is executed with two arguments:
  1. The PID of the server
  2. A string to be sent

- The client sends the string **character by character, bit by bit**, using:
  - `SIGUSR1` to represent binary `1`
  - `SIGUSR2` to represent binary `0`

- The server receives these signals and reconstructs the original message, printing it to `stdout`.

---

## Installation & Compilation

```bash
git clone https://github.com/ahmeterenyasar/minitalk.git
cd minitalk
make
```

**For bonus:**

```bash
make bonus
```

## Usage

### Terminal 1: Start the Server

```bash
./server # Output: Server PID: 12345
```

### Terminal 2: Start the Client

```
./client 12345 "Hello, World!"
```

> The server will print:

`Hello, World!`

---

## License

This project is for academic and personal learning purposes only.
