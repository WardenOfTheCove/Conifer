#include <gladlib/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <morecmath/funcs.hpp>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/geometric.hpp>

class transformations {
    public:
        glm::mat4x4 position(glm::mat4 vertices, glm::vec3 location) {
            glm::mat4x4 worldVertices;
            glm::vec4 check(vertices[3][0], vertices[3][1], vertices[3][2], vertices[3][3]);
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 4; j++) {
                    vertices[i][j] += location[i];
                }
           }
            glm::vec4 check2(vertices[3][0], vertices[3][1], vertices[3][2], vertices[3][3]);
            if(check != check2) {
                return -1;
            }
            for(int k = 0; k < 4; k++) {
                worldVertices[k] = glm::normalize(vertices[k]);
            }
           return worldVertices;
        }
        

};