#include <gtkmm.h>
#include <iostream>

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.gcomte.hellocmake");
    Gtk::Window window;
    window.set_title("Hello cmake");
    window.set_default_size(400, 300);
    Gtk::Label *pLabel = Gtk::manage(new Gtk::Label("Label"));
    pLabel->show();
    window.add(*pLabel);
    return app->run(window);
}
