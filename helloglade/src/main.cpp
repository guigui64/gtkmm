#include <gtkmm.h>
#include <iostream>

int main (int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    auto builder = Gtk::Builder::create_from_file("glade/hello.glade");

    Gtk::Window *pWindow = nullptr;
    builder->get_widget("main_window", pWindow);
    Gtk::Dialog *pDialog = nullptr;
    builder->get_widget("dialog", pDialog);

    Gtk::Button *pShowDialogButton = nullptr;
    builder->get_widget("show_dialog_button", pShowDialogButton);
    pShowDialogButton->signal_clicked().connect([pDialog] {
        pDialog->show();
    });

    Gtk::Entry *pNameEntry = nullptr;
    builder->get_widget("name_entry", pNameEntry);
    Gtk::Button *pHelloButton = nullptr;
    builder->get_widget("hello_button", pHelloButton);
    pHelloButton->signal_clicked().connect([pNameEntry] {
        std::cout << "Hello " << pNameEntry->get_text() << std::endl;
    });

    Gtk::Button *pQuitButton = nullptr;
    builder->get_widget("quit_button", pQuitButton);
    pQuitButton->signal_clicked().connect([pDialog] {
        pDialog->hide();
    });

    return app->run(*pWindow);
}
