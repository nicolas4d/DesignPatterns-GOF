#ifndef WINDOW_H
#define WINDOW_H

#include "visualComponent.cpp"

class Window
{
public:
  Window();
  void SetContents (VisualComponent* contents);
};

Window::Window()
{
  std::cout << "Window::Window()" << "\n";
}

void Window::SetContents (VisualComponent* contents)
{
  std::cout << "void Window::SetContents (VisualComponent* contents)" << "\n";
  contents->Draw();
}

#endif /* WINDOW_H */
