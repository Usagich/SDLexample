/** @file ngage_appui.h
 *
 *  A simple SDL 2.0.x sample project.
 *
 *  Do not modify this file unless absolutely necessary.
 *  All project-specific settings can be found in the file:
 *  project_config.cmake
 *
 *  To the extent possible under law, Michael Fitzmayer has waived all
 *  copyright and related or neighboring rights to SDLexample.  This
 *  work is published from: Germany.
 *
 *  CC0 http://creativecommons.org/publicdomain/zero/1.0/
 *  SPDX-License-Identifier: CC0-1.0
 *
 **/

#ifndef NGAGE_APPUI_H
#define NGAGE_APPUI_H

#include <aknappui.h>

class CNGageAppView;

class CNGageAppUi : public CAknAppUi
{
public:
    void ConstructL();

    CNGageAppUi();
    ~CNGageAppUi();

public:
    void HandleCommandL(TInt aCommand);

private:
    CNGageAppView* iAppView;
};

#endif /* NGAGE_APPUI_H */
