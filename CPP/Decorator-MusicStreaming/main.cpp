#include "PlayMusic.hpp"
#include "Eco.hpp"
#include "Equalize.hpp"
#include "Reverb.hpp"
#include "SoundEffects.hpp"

int main(void)
{

    PlayMusic* music = new Eco( new Equalize(new Reverb( new SoundEffects( new PlayMusic()))));

    music->play();
}