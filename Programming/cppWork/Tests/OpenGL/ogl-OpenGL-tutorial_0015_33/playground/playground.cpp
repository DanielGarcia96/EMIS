// Include the standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW. Always include it before gl.h and glfw.h,
// since it's a bit magic.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);

int main()  {

   // Initialise GLFW
   if ( !glfwInit() )  {
      fprintf(stderr, "Failed to initialize GLFW\n");
      return -1;
   }

   glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want
                                                  // OpenGL 3.3
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   // To make MacOS happy; should not be needed
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   // We don't want the old OpenGL

   // Open a window and create its OpenGL context
   GLFWwindow* window;
   // (In the accompanying source code, this variable is global)
   window = glfwCreateWindow(1024, 768, "Tutorial 02", NULL, NULL);
   if ( window == NULL )  {
      fprintf(stderr, "Failed to open GLFW window. ");
      fprintf(stderr, "If you have an Intel GPU, ");
      fprintf(stderr, "they are not 3.3 compatible. ");
      fprintf(stderr, "Try the 2.1 version of the tutorials.\n");
      glfwTerminate();
      return -1;
   }
   
   glfwMakeContextCurrent(window); // Initialize GLEW
   glewExperimental = true; // Needed in core profile
   if ( glewInit() != GLEW_OK )  {
     fprintf(stderr, "Failed to initialize GLEW\n");
     return -1;
   }

   glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

   GLuint VertexArrayID;
   glGenVertexArrays(1, &VertexArrayID); 
   glBindVertexArray(VertexArrayID); 
   
   // An array of 3 vectors which represents 3 vertices
   static const GLfloat g_vertex_buffer_data[] = {
      -1.0f, -1.0f, 0.0f,
      1.0f, -1.0f, 0.0f,
      0.0f, 1.0f, 0.0f,
   };

   // This will identify our vertex buffer
   GLuint vertexbuffer;
   
   // Generate 1 buffer, put the resulting identifier in vertexbuffer
   glGenBuffers(1, &vertexbuffer);
   // The following commands will talk about our 'vertexbuffer' buffer
   glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
   //Give our vertices to OpenGL
   glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
                g_vertex_buffer_data, GL_STATIC_DRAW);

   //Ensure we can capture the escape key being pressed below
   glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLuint programID = LoadShaders(
                       "SimpleVertexShader.vertexshader",
                       "SimpleFragmentShader.fragmentshader");
    
   do  {
      // Clear the screen
      glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      // Use our shader
      glUseProgram(programID); 

      // Draw triangle...
      // 1rst attribute buffer : vertices
      glEnableVertexAttribArray(0);
      glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
      glVertexAttribPointer(
         0,                // attribute 0. No particular reason for 0, but must match the layout in the shader.
         3,                // size
         GL_FLOAT,         // type
         GL_FALSE,         // normalized?
         0,                // stride
         (void*)0          // array buffer offset
      );
    
      //Draw triangle!
      glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
      glDisableVertexAttribArray(0);

      //Swap buffers
      glfwSwapBuffers(window);
      glfwPollEvents();
   } // Check if the ESC key was pressed or the window was closed
   while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
   return 0;
}