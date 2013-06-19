/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 *
 *      Ported to SFML 2.0 by xerpi
 */


#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

bool	fullscreen=false;	// Fullscreen Flag Set To Fullscreen Mode By Default
bool    vsync=true;         // Turn VSYNC on/off
bool	light;				// Lighting ON/OFF ( NEW )

GLfloat	xrot;				// X Rotation
GLfloat	yrot;				// Y Rotation
GLfloat xspeed;				// X Rotation Speed
GLfloat yspeed;				// Y Rotation Speed
GLfloat	z=-5.0f;			// Depth Into The Screen

GLfloat LightAmbient[]=		{ 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]=		{ 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[]=	{ 0.0f, 0.0f, 2.0f, 1.0f };

GLuint	filter;				// Which Filter To Use
GLuint	texture[3];			// Storage For 3 Textures

int LoadGLTextures()									// Load Bitmaps And Convert To Textures
{
	int Status=false;									// Status Indicator

	// Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
	sf::Image Image;
	if (Image.loadFromFile("Data/NeHe.bmp"))
	{
		Status=true;									// Set The Status To true

        glGenTextures(3, &texture[0]);					// Create Three Textures

		// Create Nearest Filtered Texture
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, Image.getSize().x, Image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Image.getPixelsPtr());

		// Create Linear Filtered Texture
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, Image.getSize().x, Image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, Image.getPixelsPtr());

		// Create MipMapped Texture
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, Image.getSize().x, Image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, Image.getPixelsPtr());
	}

	return Status;										// Return The Status
}

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int InitGL()										    // All Setup For OpenGL Goes Here
{
    if (!LoadGLTextures())								// Jump To Texture Loading Routine
	{
		return false;									// If Texture Didn't Load Return false
	}

	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);		// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);		// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);	// Position The Light
	glEnable(GL_LIGHT1);								// Enable Light One
	return true;										// Initialization Went OK
}

int DrawGLScene()									    // Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The View
	glTranslatef(0.0f,0.0f,z);

	glRotatef(xrot,1.0f,0.0f,0.0f);
	glRotatef(yrot,0.0f,1.0f,0.0f);

	glBindTexture(GL_TEXTURE_2D, texture[filter]);

	glBegin(GL_QUADS);
		// Front Face
		glNormal3f( 0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
		glNormal3f( 0.0f, 0.0f,-1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
		glNormal3f( 0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
		glNormal3f( 0.0f,-1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		// Right face
		glNormal3f( 1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();

	xrot+=xspeed;
	yrot+=yspeed;
	return true;										// Keep Going
}

int main()
{
    // Create the main window
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML/NeHe OpenGL");

    InitGL();
    ReSizeGLScene(800, 600);

    // Start game loop
    while (App.isOpen())
    {
        // Process events
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // close window : exit
            if (Event.type == sf::Event::Closed)
                App.close();

            // Resize event : adjust viewport
            if (Event.type == sf::Event::Resized)
                ReSizeGLScene(Event.size.width, Event.size.height);

            // Handle Keyboard Events
            if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Escape:
                        App.close();
                        break;
                    case sf::Keyboard::F1:
                        fullscreen = !fullscreen;
                        App.create(fullscreen ? sf::VideoMode::getDesktopMode() : sf::VideoMode(800, 600, 32) , "SFML/NeHe OpenGL",
                        (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize | sf::Style::Close));
                        ReSizeGLScene(App.getSize().x,App.getSize().y);
                        break;
                    case sf::Keyboard::F5:
                        vsync = !vsync;
                        break;
                    case sf::Keyboard::L:
                        light=!light;
                        if (!light) {
                            glDisable(GL_LIGHTING);
                        } else {
                            glEnable(GL_LIGHTING);
                        }
                        break;
                    case sf::Keyboard::F:
                        filter+=1;
                        if (filter>2) {
                            filter=0;
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        //Handle movement keys


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {
            z-=0.02f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) {
            z+=0.02f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            xspeed-=0.01f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            xspeed+=0.01f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            yspeed+=0.01f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            yspeed-=0.01f;
        }

        // Turn VSYNC on so that animations run at a more reasonable speed on new CPU's/GPU's.
        App.setVerticalSyncEnabled(vsync);

        // Set the active window before using OpenGL commands
        // It's useless here because active window is always the same,
        // but don't forget it if you use multiple windows or controls
        App.setActive();

        //Draw some pretty stuff
        DrawGLScene();

        // Finally, display rendered frame on screen
        App.display();
    }

    return EXIT_SUCCESS;
}
