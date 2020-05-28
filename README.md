# Floodfill2_0

A c++ floodfiller and cell size calculator for 4-square connections.

## Getting Started

There are 2 classes a 'floodfiller' and 'floodfillersize' class for 2 different purposes. The floodfiller is designed to perform a flood fille to an integer or boolean map and overwrite the input given. The floodfillersize uses the floodfiller algorithm to give back the size of that 'chamber'.

The following will return the size of an int/boolean 2d matrix as well as overwrite that data.
```cpp
floodfiller filler = floodfiller(Width, Height);
int size = filler.floodfill(matrix, pos1, pos2, cor);
```
The following will return the size of an int/boolean 2d matrix but not overwrite that data.
```cpp
floodfillersize filler = floodfillersize(Width, Height);
int size = filler.getSize(matrix, pos1, pos2);
```

* Note this is handled with static memory for performance where the maximum length is given by the maplen.h file.

See the myfloodfill.cpp file for execution of various problems.

## Authors

* **Daniel Stamer-Squair** - *UaineTeine*

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.