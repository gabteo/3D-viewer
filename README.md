# 3D Viewer
Computer Graphics project for viewing 3D .obj files using OpenGL

![image](https://img.shields.io/badge/C++-00599C.svg?style=for-the-badge&logo=C++&logoColor=white)
![image](https://img.shields.io/badge/OpenGL-5586A4.svg?style=for-the-badge&logo=OpenGL&logoColor=white)

<p align="center">
<img src="docs/00-intro3.gif">
</p>

# Supported features
- Vertex loading (using Assimp lib)
- Geometric transforms
- Normal and wireframe views
<p align="center">
<img src="docs/02-mario-wireframe.gif" alt= “” width="40%" height="40%">
</p>

# Usage
This software is compatible with Linux environments. 

## Build
If the file ```mesh``` isnt available, run ```make```. That's it!

## Executing
Run
```bash
./mesh [filepath]
```

For example, try 
```bash
./mesh resource/backpack.object 
```

## Usage
| Key | Action |
| --- | --- |
| `s` or `e` | Enter scale mode |
| `t` | Enter translation mode |
| `r` | Enter translation mode (default mode) |
| `v` | Toggle wireframe view. Defauldt value is disabled. |
| `p` | Toggle perspective mode (orthogonal or perspective). Default view is orthogonal. |

Use the arrow keys, `a` and `d` for changing parameters in each mode.

### In scale mode:

<p align="center">
<img src="docs/01-mario-zoom.gif" alt= “” width="40%" height="40%">
</p>

| Key | Action |
| --- | --- |
| = | Increase scale proportionally |
| - | Decrease scale proportionally |
| Left and right arrows | Change scale in x-axis |
| Down and up arrows | Change scale in y-axis |
| `a` and `d` | Change scale in z-axis |

### In translation mode:

| Key | Action |
| --- | --- |
| Left and right arrows | Move in x-axis |
| Down and up arrows | Move in y-axis |
| `a` and `d` | Move in z-axis |

### In rotation mode:

| Fill | Wireframe |
| --- | --- |
|[](docs/03-mario-rotate.gif) | [](docs/04-mario-rotate-wireframe.gif) |


| Key | Action |
| --- | --- |
| Left and right arrows | Rotate in y-axis |
| Down and up arrows | Rotate in x-axis |
| `a` and `d` | Rotate in z-axis |

# Other demonstrations


# Dependencies
All the dependencies are included.

| Library | Link | Documentation |
| --- | --- | --- |
| OpenGL | |
| Glut | |
| assimp | https://github.com/assimp/assimp | https://assimp-docs.readthedocs.io/ |

# References

Many of the code is based on the great tutorials by Learn OpenGL available at https://learnopengl.com/Model-Loading/Model and on the Computer Graphics lectures at the Federal University of Parana (UTFPR) in the first semester of 2023.

The backpack model was suggested by the same tutorial, and is designed by Berk Gedik. It's available for download here: [Survival Guitar Backpack](https://skfb.ly/6QZxW).
