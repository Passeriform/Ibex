#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "grid.h"

Grid::Grid(std::pair<int, int> dim, int gridSize, glm::vec3 color) : Mesh() {
	vertexShaderPath = "shaders/gridShader.vert";
	fragmentShaderPath = "shaders/gridShader.frag";

	show = true;

	int slicex = dim.first / static_cast<float>(gridSize);
	int slicey = dim.second / static_cast<float>(gridSize);

	// vertex positions
	for (int i = -(slicey / 2); i < (slicey / 2); i++) {
		for (int j = -(slicex / 2); j < (slicex / 2); j++) {
			float x = static_cast<float>(j);
			float y = 0;
			float z = static_cast<float>(i);

			vertices.emplace_back(Vertex(glm::vec3(x, y, z), glm::vec3(0.0f, 1.0f, 0.0f), color));
		}
	}

	// vertex indices
	// Insert left and top line for each row till second from bottom.
	for (int i = 0; i < slicey - 1; i++) {
		for (int j = 0; j < slicex - 1; j++) {
			unsigned int topLeft = (i * (slicex)) + j;
			unsigned int topRight = topLeft + 1;
			unsigned int bottomLeft = topLeft + slicex;

			std::vector<unsigned int> lineIndices = {
				topRight, topLeft,			// Top line
				topLeft, bottomLeft,		// Left line
			};

			locations.insert(locations.end(), lineIndices.begin(), lineIndices.end());
		}

		// Insert right line for each row's last column.
		unsigned int topRight = (((i + 1) * slicex) - 1);
		unsigned int bottomRight = topRight + slicex;
		locations.insert(locations.end(), { bottomRight , topRight });
	}

	// Insert bottom line for bottom row.
	for (int j = 0; j < slicex - 1; j++) {
		unsigned int bottomLeft = ((slicey - 1) * slicex) + j;
		unsigned int bottomRight = bottomLeft + 1;

		locations.insert(locations.end(), { bottomLeft, bottomRight });
	}
}

int Grid::bindAttributes() {
	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));
	glEnableVertexAttribArray(0);

	// Bind color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, color)));
	glEnableVertexAttribArray(1);

	return 0;
}

int Grid::draw(std::shared_ptr<Camera> camera, std::pair<float, float> scrDim, DrawOptions drawOptions) {
	return Mesh::draw(camera, scrDim, drawOptions);
}
