#ifndef VISUALCOMPONENT_H
#define VISUALCOMPONENT_H

class VisualComponent {
public:
  VisualComponent();

  virtual void Draw();
  virtual void Resize();
  // ...
};

VisualComponent::VisualComponent()
{
  std::cout << "VisualComponent::VisualComponent()" << "\n";
}

void VisualComponent::Draw()
{
  std::cout << "VisualComponent::Draw()" << "\n";
}

void VisualComponent::Resize()
{
  std::cout << "VisualComponent::Resize()" << "\n";
}

#endif /* VISUALCOMPONENT_H */
