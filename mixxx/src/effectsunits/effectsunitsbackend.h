#ifndef EFFECTSUNITSBACKEND_H
#define EFFECTSUNITSBACKEND_H

#include <QtCore>
#include <QDebug>

#include "effectsunitsplugin.h"
#include "../engine/engineeffectsunits.h"
#include "../defs.h"

class EffectsUnitsPlugin;
class EngineEffectsUnits;

/* EffectsUnitsBackend:
 * loadPlugins() -> Load all plugins into m_BackendPlugins, assign id # for each one.
 * process() -> A process call will be forwarded from plugin, along with plugin id #
 * activatePlugin() -> This will be called before process(), along with plugin id #
 */

class EffectsUnitsBackend {
public:
	EffectsUnitsBackend();
	virtual ~EffectsUnitsBackend();

	QString getName();
	EffectsUnitsBackend * getBackend();
	QList<EffectsUnitsPlugin *> * getPlugins();

	virtual void loadPlugins();
	virtual void process(const CSAMPLE *pIn, const CSAMPLE *pOut, const int iBufferSize, int PluginID);
	virtual void activatePlugin(int PluginID);
	virtual void deactivatePlugin(int PluginID);

protected:
	QString * m_Name;								// Name of the Backend (possibly useless since every backend will have its own class)
	QList<EffectsUnitsPlugin *> m_BackendPlugins;	// List of available plugins on this Backend
	int PluginIDSequence;						// Holds the ID for the next plugin to be loaded.
};


#endif
