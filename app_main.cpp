#include "App.cpp"


int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 600, 600, "game");

    app->run();
}
