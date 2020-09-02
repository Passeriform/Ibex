# Ibex
openGL-based graphics engine using GLFW and GLAD.

An attempt at creating a home-grown graphics engine from scratch. Uses GLFW, GLAD and GLM under the hood. The aim is to build an extensible (and insanity-free) framework with apt programming design philosophy and standards.

## Features

### Engine
Everything starts with an instance of the engine. Initiate that using `init()` and start by loading a `World`.

---

### World
A world is a scene entity, comprising all configurations, positions and (generally) non-persistent changes to individual elements. `World` is an interface for creating new worlds using the predefined common methods and the mystical power of **overloading**.

#### Void
`Void` is a world with loaded `Grid` and a `Cube` as a startup `World` to experiment with. `Void` contains a singular `OmniDirectionLight` and shaders to show light interactions.

---

### Mesh
An interface to make **models** (`Element`) from raw vertices. A mesh intentionally relies on foreign shaders to allow hot-swap ease from a (possible) global scope.

#### Triangle
A 2D right-angled triangle in 3D space as an example of 2D polygon drawing.

#### Cube
A 3D cube in 3D space as an example of 3D polyhedron drawing.

---

### Lighting
An interface to define the form and function of light within the `World`.

#### OmniDirectionLight
A `Lighting` instance of point-centric light source with coupled Phong-shading config.

---

### Material
An interface for defining surface material with light-interaction specifications.

---

### Events
An event-handling service for registering event callbacks and evaluate `World` states continuously.

---

### Camera
A miniscule class for describing in-world camera mechanics and provide the view as an entity to various modules.

---

### Shader
A convenience utility for describing and passing shader objects around using a thin wrapper on the underlying gl calls.

---

## Resources
[LearnOpenGL](https://learnopengl.com/)                       \
[openGL Tutorial](http://www.opengl-tutorial.org/)            \
[Khronos openGL Wiki](https://www.khronos.org/opengl/wiki/)   \
[Khronos openGL Community](https://community.khronos.org/)    \
[Solarian Programmer Blog](https://solarianprogrammer.com/)   \
[Frédéric Devernay's Website](devernay.free.fr/cours/opengl/) \
[The openGL Guide](https://open.gl/)                          \
[Stack Overflow](https://stackoverflow.com/) (For obvious reasons)
