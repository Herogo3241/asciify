# ASCII Art Renderer

A simple C++ program that converts an image to ASCII art using OpenCV. This tool allows you to generate text-based representations of images, which can be useful for various purposes, including displaying images in text-based environments.

## Features

- Converts images to grayscale.
- Resizes images to a specified width while maintaining aspect ratio.
- Renders the grayscale image into ASCII art using a set of ASCII characters.
- Supports optional size specification with a default size of 80.

## Video
[![YouTube Video](https://img.youtube.com/vi/DCgSY7DrJ78/0.jpg)](https://youtu.be/DCgSY7DrJ78)


## Requirements


- Linux
- OpenCV
- C++11 or higher

## Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/Herogo3241/asciify.git
   cd asciify
   ```

2. **Install OpenCV:**

   Follow the [OpenCV installation guide](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html) for your operating system.

3. **Build the project using Make:**

   ```bash
   chmod +x install.sh
   ./install.sh
   ```

   This command will compile the program and produce an executable named `asciify`.

## Usage

To generate ASCII art from an image, use the following command:

```bash
asciify --image <image_path> [--size <width>]
```

- `--image <image_path>`: Path to the input image file.
- `--size <width>`: Optional width for the output ASCII art (default is 80).

### Different Approach

1. **Convert an image with the default width:**

   ```bash
   asciify --image path_to_image.jpg
   ```

2. **Convert an image with a specified width:**

   ```bash
   asciify --image path_to_image.jpg --size 100
   ```

## Makefile

The project includes a `Makefile` for building the project. Here's a brief overview of the targets:

- `make`: Builds the executable `asciify`.
- `make clean`: Removes the compiled executable and any temporary files.


## Acknowledgments

- This project uses OpenCV for image processing.
- ASCII art techniques inspired by various online resources.

