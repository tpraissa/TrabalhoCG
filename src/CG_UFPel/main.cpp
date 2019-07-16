#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/spline.hpp>

#include <learnopengl/filesystem.h>
#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>
#include <learnopengl/model.h>
#include <iostream>
#include <unistd.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void processInput(GLFWwindow *window);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
Shader buildShader();
Model loadModel();
Shader buildShader2();
Model loadModel2();
void update();

//Shader
Shader ourShader;
Shader ourShader2;

//Model
Model ourModel;
Model ourModel2;


GLFWwindow* window1;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//bool firstMouse = true;
glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;


float now = glfwGetTime();
static float last_update = now;
float delta_time = now - last_update;

bool modPos = true;
bool pressPos = false;
bool press = false;
//keyboard
bool d_press;
bool u_press;
bool t_press;
bool l_press;
int flag;
int v_rep = 1;
float ri_press = 0.0f;
float sc_xyz = 0.004f;
float pos_x = 0.0f;
float pos_y = 0.0f; 
float pos_z = 0.0f;
float angulo = 20.0f;
float px = 0.01f;
float py = 0.01f;
float pz = 0.01f;
float move_x = 0.02f;
float move_y = 0.01f;
float max_x = 1.67f;
float max_y = 1.22f;
float min_x = -1.67f;
float min_y = -1.22f;

float scxH = 0.001f;
float scyH = 0.001f;
float scxV = 0.0005f;
float scyV = 0.003f;

float mousex;
float mousey;
float nowx = 0.0f;
float nowy = 0.0f; 
float radiano;
float camX;
float camZ;
bool rotateCam;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    window1 = window;

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    //glfwSetScrollCallback(window, scroll_callback);
    glfwSetKeyCallback(window, keyCallback);
    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // draw in wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE)

    //ourShader2 = buildShader2();
    ourShader = buildShader();
    ourModel = loadModel();
    ourModel2 = loadModel2();
    ourShader.use();
    //ourShader2.use();



    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
 
        // input
        processInput(window);

        // render
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // don't forget to enable shader before setting uniforms
        // view/projection transformations
        //glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        //glm::mat4 view = camera.GetViewMatrix();
        //ourShader.setMat4("projection", projection);
        //ourShader.setMat4("view", view);
        //glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        //glm::mat4 view1 = glm::mat4(1.0f);
        //radiano = 10.0f;
        //camX   = sin(glfwGetTime()) * radiano;
        //camZ   = cos(glfwGetTime()) * radiano;
        //view1 = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        //ourShader.setMat4("view", view1);

        //camera
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);  
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        ourShader.use();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
        //ourShader2.use();
        //ourShader2.setMat4("projection", projection);
        //ourShader2.setMat4("view", view);

        //glm::mat4 model2 = glm::mat4(1.0f);
        //model2 = glm::translate(model2, glm::vec3(0.0f, 0.0f, 0.0f)); 
        //model2 = glm::scale(model2, glm::vec3(0.01f, 0.01f, 0.01f));   
        //ourShader2.setMat4("model", model2);
        //ourModel2.Draw(ourShader2);


        usleep(30000);
        ourShader.use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(pos_x, pos_y, pos_z)); 
        model = glm::scale(model, glm::vec3(sc_xyz, sc_xyz, sc_xyz));   
        ourShader.setMat4("model", model);
        ourModel.Draw(ourShader);
        pos_x = pos_x - move_x;
        pos_y = pos_y + move_y;
        printf("%f\n", pos_x );
        printf("%f\n", pos_y );
        printf("\n");
        printf("%f\n", move_x );
        printf("%f\n", move_y );
        printf("\n");
        if (pos_x > max_x){
            move_x = move_x * -1;
            //move_y = move_y * -1;
        }
        if (pos_y > max_y){
            //move_x = move_x * -1;
            move_y = move_y * -1;
        }
        if (pos_x < min_x){
            move_x = move_x * -1;
            //move_y = move_y * -1;
        }
        if (pos_y < min_y){
            //move_x = move_x * -1;
            move_y = move_y * -1;
        }
        if (pressPos == true){
            if (modPos == true){
                if (mousex < 0){
                    min_y = nowy;
                }else{
                    max_y = nowy;
                }
            } else {
                if (mousey <= 0){
                    min_x = nowx;
                }else{
                    max_x = nowx;
                }
                
            }
        }







        unsigned int amount = 20;
        glm::mat4* modelMatrices;
        modelMatrices = new glm::mat4[amount];
        if (modPos == true)
        {
            glm::mat4 model1 = glm::mat4(1.0f);
            model1 = glm::translate(model1, glm::vec3(mousex, mousey, 0.0f));
            model1 = glm::scale(model1, glm::vec3(scxH, scyH, 0.001f));
            modelMatrices[0] = model1;
        }else{
            glm::mat4 model1 = glm::mat4(1.0f);
            model1 = glm::translate(model1, glm::vec3(mousex, mousey, 0.0f));
            model1 = glm::scale(model1, glm::vec3(scxV, scyV, 0.001f));
            modelMatrices[0] = model1;
        }

        if (pressPos == true){
            if (press == true){
                nowx = mousex;
                nowy = mousey;
                press = false;
            }
            if (modPos == true){
                scxH += 0.00008f;
                glm::mat4 model1 = glm::mat4(1.0f);
                model1 = glm::translate(model1, glm::vec3(nowx, nowy, 0.0f));
                model1 = glm::scale(model1, glm::vec3(scxH, scyH, 0.001f));
                modelMatrices[0] = model1;
            } else{
                scyV += 0.00009f;
                glm::mat4 model1 = glm::mat4(1.0f);
                model1 = glm::translate(model1, glm::vec3(nowx, nowy, 0.0f));
                model1 = glm::scale(model1, glm::vec3(scxV, scyV, 0.001f));
                modelMatrices[0] = model1;
            }
        }
        printf("\n%f\n", scxH);
        printf("%f\n", scyV);

        for (unsigned int i = 1; i < amount; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
            model = glm::scale(model, glm::vec3(0.001f, 0.001f, 0.001f));
            modelMatrices[i] = model;
        }

        ourShader.setMat4("model", modelMatrices[0]);
        ourModel2.Draw(ourShader);

        double xpos, ypos;
        glfwGetCursorPos( window, &xpos, &ypos );



        printf("%f\n", mousex);
        printf("%f\n", mousey);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

//---------------------

Shader buildShader(){
    // build and compile shaders
    // -------------------------
    Shader ourShader(FileSystem::getPath("resources/cg_ufpel.vs").c_str(), FileSystem::getPath("resources/cg_ufpel.fs").c_str());
    return ourShader;
}

Model loadModel(){
   // load models
    // -----------
    Model ourModel(FileSystem::getPath("resources/objects/ball/13517_Beach_Ball_v2_L3.obj"));
    return ourModel;
}

Shader buildShader2(){
    // build and compile shaders
    // -------------------------
    Shader ourShader2(FileSystem::getPath("resources/cg_ufpel2.vs").c_str(), FileSystem::getPath("resources/cg_ufpel2.fs").c_str());
    return ourShader2;
}

Model loadModel2(){
   // load models
    // -----------
    Model ourModel2(FileSystem::getPath("resources/objects/parede/10449_Rectangular_Box_Hedge_v1_iterations-2.obj"));
    return ourModel2;
}

void update(){
    processInput(window1);

    // render
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // don't forget to enable shader before setting uniforms
    ourShader.use();
    //ourShader2.use();

    // view/projection transformations
    //glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    //glm::mat4 view = camera.GetViewMatrix();
    //ourShader.setMat4("projection", projection);
    //ourShader.setMat4("view", view);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    ourShader.setMat4("projection", projection); 
   // ourShader2.setMat4("projection2", projection); 
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    //float cameraSpeed = 2.5 * deltaTime; 
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    float cameraSpeed = 2.5 * deltaTime; 
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

   // if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
   //     camera.ProcessKeyboard(FORWARD, deltaTime);
   // if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
   //     camera.ProcessKeyboard(BACKWARD, deltaTime);
   // if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
   //     camera.ProcessKeyboard(LEFT, deltaTime);
   // if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
   //     camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    double xp, yp;
    glfwGetCursorPos(window, &xp, &yp);
    mousex = (2.0f*(float)xp / (float)(SCR_WIDTH-1)) - 1.0f;
    mousey = 1.0f - (2.0f*(float)yp / (float)(SCR_HEIGHT-1));
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }

//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

//    lastX = xpos;
//    lastY = ypos;

//    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    camera.ProcessMouseScroll(yoffset);
//}


void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
        if (modPos  == true){
            modPos = false; //horizontal
        }
        else {
            modPos = true;
        }
    } else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        pressPos = true;
        press = true;
    }
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)	 
{   
    switch (key)
    {   
        case GLFW_KEY_RIGHT:
            if (action == GLFW_PRESS){
                pos_x += 0.1f;
                t_press = true;     
            }
            break;
        
    }
}