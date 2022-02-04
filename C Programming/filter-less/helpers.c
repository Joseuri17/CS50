#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
                image[i][j].rgbtRed = avg;
                image[i][j].rgbtBlue = avg;
                image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    int originalRed;
    int originalGreen;
    int originalBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        originalRed = image[i][j].rgbtRed;
        originalBlue = image[i][j].rgbtBlue;
        originalGreen = image[i][j].rgbtGreen;

        sepiaRed = (int) round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
        sepiaGreen = (int) round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
        sepiaBlue = (int) round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
        if (sepiaRed > 255)
        {
            sepiaRed = 255;
        }
        if (sepiaGreen > 255)
        {
            sepiaGreen = 255;
        }
        if (sepiaBlue > 255)
        {
            sepiaBlue = 255;
        }

        image[i][j].rgbtRed = sepiaRed;
        image[i][j].rgbtGreen = sepiaGreen;
        image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    double red;
    double green;
    double blue;

    //RGBTRIPLE k[Height][width]

    for (int i = 0; i < height; i++)
    {
        int k = width - 1;
        for (int j = 0; j < width/2; j++)
        {
            red = image[i][j].rgbtRed;
            green  = image[i][j].rgbtGreen;
            blue  = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][k].rgbtRed;
            image[i][j].rgbtGreen = image[i][k].rgbtGreen;
            image[i][j].rgbtBlue = image[i][k].rgbtBlue;

            image[i][k].rgbtRed = red;
            image[i][k].rgbtGreen = green;
            image[i][k].rgbtBlue = blue;
            k = k - 1;
          }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //TOP LEFT CORNER (1) checks
            if (j == 0 && i == 0)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i][j+1].rgbtRed   + copy[i+1][j+1].rgbtRed   + copy[i + 1][j].rgbtRed)   / 4.);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i+1][j+1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i][j+1].rgbtBlue  + copy[i+1][j+1].rgbtBlue  + copy[i + 1][j].rgbtBlue)  / 4.0);
            }
            //TOP RIGHT CORNER (2) checks
            else if (j == width - 1 && i == 0)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i][j-1].rgbtRed   + copy[i+1][j-1].rgbtRed   + copy[i + 1][j].rgbtRed)   / 4.0);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i][j-1].rgbtBlue  + copy[i+1][j-1].rgbtBlue  + copy[i + 1][j].rgbtBlue)  / 4.0);
            }
            //TOP SIDE (8) checks
            else if (i == 0)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i][j-1].rgbtRed   + copy[i+1][j-1].rgbtRed   + copy[i+1][j].rgbtRed   + copy[i+1][j+1].rgbtRed   + copy[i][j+1].rgbtRed)   / 6.0);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i][j-1].rgbtBlue  + copy[i+1][j-1].rgbtBlue  + copy[i+1][j].rgbtBlue  + copy[i+1][j+1].rgbtBlue  + copy[i][j+1].rgbtBlue)  / 6.0);
            }
            //BOTTOM LEFT CORNER (3)  checks
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i-1][j].rgbtRed   + copy[i-1][j+1].rgbtRed   + copy[i][j+1].rgbtRed)   / 4.0);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i-1][j].rgbtBlue  + copy[i-1][j+1].rgbtBlue  + copy[i][j+1].rgbtBlue)  / 4.0);
            }
            // BOTTOM RIGHT CORNER (4) checks
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i-1][j].rgbtRed   + copy[i-1][j-1].rgbtRed   + copy[i][j-1].rgbtRed)   / 4.0);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i][j-1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i-1][j].rgbtBlue  + copy[i-1][j-1].rgbtBlue  + copy[i][j-1].rgbtBlue)  / 4.0);
            }
            //BOTTOM SIDE (6) checks
            else if (i == height - 1)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i][j-1].rgbtRed   + copy[i-1][j-1].rgbtRed   + copy[i-1][j].rgbtRed   + copy[i-1][j+1].rgbtRed   + copy[i][j+1].rgbtRed)   / 6.0);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i][j-1].rgbtBlue  + copy[i-1][j-1].rgbtBlue  + copy[i-1][j].rgbtBlue  + copy[i-1][j+1].rgbtBlue  + copy[i][j+1].rgbtBlue)  / 6.0);
            }
            // LEFT SIDE (5) checks
            else if (j == 0)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i-1][j].rgbtRed   + copy[i-1][j+1].rgbtRed   + copy[i][j+1].rgbtRed   + copy[i+1][j+1].rgbtRed   + copy[i+1][j].rgbtRed)   / 6.0);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i+1][j+1].rgbtGreen + copy[i+1][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i-1][j].rgbtBlue  + copy[i-1][j+1].rgbtBlue  + copy[i][j+1].rgbtBlue  + copy[i+1][j+1].rgbtBlue  + copy[i+1][j].rgbtBlue)  / 6.0);
            }
            // RIGHT SIDE (7) checks
            else if(j == width - 1)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i-1][j].rgbtRed   + copy[i-1][j-1].rgbtRed   + copy[i][j-1].rgbtRed   + copy[i+1][j-1].rgbtRed   + copy[i+1][j].rgbtRed)   / 6.0);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i-1][j].rgbtBlue  + copy[i-1][j-1].rgbtBlue  + copy[i][j-1].rgbtBlue  + copy[i+1][j-1].rgbtBlue  + copy[i+1][j].rgbtBlue)  / 6.0);
            }
            //MIDDLE (9) checks
            else if (i > 0 && j > 0)
            {
                image[i][j].rgbtRed   =  round((copy[i][j].rgbtRed   + copy[i][j+1].rgbtRed   + copy[i-1][j+1].rgbtRed   + copy[i-1][j].rgbtRed   + copy[i-1][j-1].rgbtRed   + copy[i][j-1].rgbtRed   + copy[i+1][j-1].rgbtRed   + copy[i+1][j].rgbtRed   + copy[i+1][j+1].rgbtRed)  / 9.0);
                image[i][j].rgbtGreen =  round((copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen) / 9.0);
                image[i][j].rgbtBlue  =  round((copy[i][j].rgbtBlue  + copy[i][j+1].rgbtBlue  + copy[i-1][j+1].rgbtBlue  + copy[i-1][j].rgbtBlue  + copy[i-1][j-1].rgbtBlue  + copy[i][j-1].rgbtBlue  + copy[i+1][j-1].rgbtBlue  + copy[i+1][j].rgbtBlue  + copy[i+1][j+1].rgbtBlue)  / 9.0);
            }
        }
    }
    return;
}
