#include <iostream>
#include <fstream>
#include <random>

/*
 * Text files are brilliant for lots of things, but we also need to work with files that represent pure
 * data (e.g. images), these are read in binary format.
 *
 * A binary file is not human readable, but it is much more efficient for storage purposes and generally
 * faster to process for reading too. Consider n file that represents an image that is 8 pixels wide by
 * 8 pixels tall - we need to represent three values for each pixel (red, green and blue) - which is
 * 3 * 8 * 8 (or 192) values:
 *
 * In a text file, that might look something like this:
 *
 * 242 94 96, 236 38 9, 100 35 188, 43 97 39, 129 50 162, 182 24 72, 217 101 131, 248 110 156
 * 138 131 167, 159 57 236, 81 116 224, 208 231 219, 247 96 124, 233 60 72, 7 214 211, 214 98 21
 * 230 248 92, 190 211 44, 107 48 201, 230 204 150, 60 170 117, 125 238 189, 160 215 241, 180 181 73
 * 90 211 204, 206 80 39, 118 229 172, 198 115 51, 184 172 111, 11 26 206, 154 53 131, 136 68 81
 * 161 200 107, 191 233 12, 124 124 79, 93 192 86, 191 244 215, 100 29 237, 166 107 75, 209 197 150
 * 76 13 91, 1 99 162, 129 121 77, 236 43 181, 131 16 117, 214 177 135, 186 209 116, 188 228 206
 * 180 128 136, 227 54 103, 216 12 224, 16 230 59, 16 219 80, 50 106 133, 35 17 103, 17 115 184
 * 6 48 89, 216 218 109, 246 240 195, 151 27 237, 93 172 34, 44 64 33, 36 241 182, 248 41 185
 *
 * Factoring in the white space and the commas, that comes in at about 448 bytes on the hard drive, for an
 * 8 by 8 pixel image. Meanwhile, the binary equivalent is just 192 bytes - that saving grows significantly
 * if we increase the size of the image. Going up to 1024 by 1024 pixels (a relatively small texture size
 * for modern games) and the text version is nearly 12 megabytes while the binary version is just over 3!
 *
 * Writing and reading binary files is relatively straightforward; we do not use extraction or insertion
 * operators. Instead, we typically specify separate functions for reading from and writing to a binary
 * file stream:
 */

class Colour
{
    // uint8_t (or unsigned char) is used to represent a byte of data (0-255)
    // allowing representation of 16 million colours.
    uint8_t r, g, b;
public:
    Colour(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

    void LoadFromStream(std::ifstream &stream)
    {
        stream.read(reinterpret_cast<char*>(&r), sizeof(r));
        stream.read(reinterpret_cast<char*>(&g), sizeof(g));
        stream.read(reinterpret_cast<char*>(&b), sizeof(b));
    }

    void WriteToStream(std::ofstream &stream)
    {
        stream.write(reinterpret_cast<char*>(&r), sizeof(r));
        stream.write(reinterpret_cast<char*>(&g), sizeof(g));
        stream.write(reinterpret_cast<char*>(&b), sizeof(b));
    }

    friend std::ostream &operator<<(std::ostream &os, const Colour &c)
    {
        // need to cast to int to ensure we print the number, otherwise we get the ascii representation.
        return os << static_cast<int>(c.r) << ' ' << static_cast<int>(c.g) << ' ' << static_cast<int>(c.b);
    }
};

int main()
{
    constexpr int pixel_size = 8;

    std::ofstream file("colours.bin", std::ios::binary);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0, 255);

    for (int i = 0; i < pixel_size; i++)
    {
        for (int j = 0; j < pixel_size; j++)
        {
            Colour colour(1 + dist(mt), 1 + dist(mt), 1 + dist(mt));
            colour.WriteToStream(file);
        }
    }

    return 0; 
}