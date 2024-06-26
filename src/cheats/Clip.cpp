//
// Created by somepineaple on 2/1/22.
//

#include "Clip.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <net/minecraft/client/multiplayer/WorldClient.h>
#include <imgui.h>
#include "../utils/ImGuiUtils.h"
#include "../utils/MathHelper.h"


Clip::Clip(Phantom *phantom) : Cheat("Clip", "Set the players position") {
    this->phantom = phantom;

    teleport = true;
    type = false;
    getPosition = false;

    x = 0;
    y = 0;
    z = 0;
    looking = 0;
}

void Clip::run(Minecraft *mc) {
    EntityPlayerSP player = mc->getPlayerContainer();


    if(getPosition) {
        getPosition = false;
        x = player.getPosX();
        y = player.getPosY();
        z = player.getPosZ();
    }

    if(teleport) {
        /* Vec3 look = player.getLookContainer(mc->getTimerContainer().getPartialTicks()); */
        /* Vec3 coords = player.getPositionVector().addVectorContainer(look.getXCoord(), look.getYCoord(), look.getZCoord()); */
        /* player.setPosition(coords.getXCoord(), coords.getYCoord(), coords.getZCoord()); // sometimes unnecessary but helps with ux */

        if(!type)
            player.setPosition(player.getPosX() + (double)x, player.getPosY() + (double)y, player.getPosZ() + (double)z);
        else
            player.setPosition((double)x, (double)y, (double)z);
        teleport = false;
    }
}

void Clip::reset(Minecraft *mc) {
    teleport = true;
}

void Clip::renderSettings() {
    ImGui::Checkbox("Absolute", &type);
    ImGui::SameLine();
    ImGuiUtils::drawHelper("Absolute position will set the players position to world x,y,z coordinates"
                           "If Absolute position is false, the player will be teleported x,y,z relative to the plaeyrs current position");

    ImGui::SliderFloat("x", &x, -10, 10, "%.5f");
    ImGui::SliderFloat("y", &y, -10, 10, "%.5f");
    ImGui::SliderFloat("z", &z, -10, 10, "%.5f");

    ImGui::SliderFloat("Looking", &looking, -10, 10, "%.5f");
    ImGui::SameLine();
    ImGuiUtils::drawHelper("Teleport in the direction the player is looking");

    if(ImGui::Button("Get position"))
        getPosition = true;

    if(ImGui::Button("Teleport"))
        teleport = true;
}
