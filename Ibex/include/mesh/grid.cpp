#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "grid.h"

Grid::Grid(std::pair<int, int> dim, int gridSize, glm::vec3 color) : Mesh() {
	int slicex = dim.first / (float)gridSize;
	int slicey = dim.second / (float)gridSize;

	// vertex positions
	for (int i = -(slicey / 2); i < (slicey / 2); i++) {
		for (int j = -(slicex / 2); j < (slicex / 2); j++) {
			float x = (float)j;
			float y = 0;
			float z = (float)i;

			vertices.push_back(Vertex(glm::vec3(x, y, z), glm::vec3(0.0f, 0.0f, 0.0f), color));
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

int Grid::draw() {
	glBindVertexArray(VAO);
	glDrawElements(GL_LINES, locations.size(), GL_UNSIGNED_INT, NULL);
	glBindVertexArray(0);

	return 0;
}
