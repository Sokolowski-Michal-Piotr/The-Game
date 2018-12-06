#include "resource_manager.hpp"

const sf::Font & my::resource_manager::fonts(const std::string & id) const
{
    auto result = fonts_.find(id);
    if (result == fonts_.end())
        throw std::runtime_error("invalid resource id");
    return result->second;
}

const sf::Texture & my::resource_manager::textures(const std::string & id) const
{
    auto result = textures_.find(id);
    if (result == textures_.end())
        throw std::runtime_error("invalid resource id");
    return result->second;
}

void my::resource_manager::load(const std::string & root)
{
    fonts_["bebas_neue"].loadFromFile(root + "fonts/bebas_neue.otf");
    textures_["ball"].loadFromFile(root + "textures/ball.png");
    for (auto& kv : textures_) kv.second.setSmooth(true);
}
