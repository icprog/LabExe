#include "GEventManager.h"
#include "Sequence/GEventNode.h"
// #include "GEventPlugin.h"
// #include "GEventShelf.h"
#include <QMimeData>
#include <QSettings>
#include <QtGui>

GEventManager::GEventManager()
 	: m_pHardEventShelf(0)
{

}

GEventManager::~GEventManager()
{

}

void GEventManager::AddEventToShelf( GEventNode* pEvent )
{
// 	if(!pEvent)
// 		return;
// 	// if the shelf doesn't exist, let's create it. Cannot be done in the constructor because it is being called before the app actually starts.
// 	HardwareEventShelf()->AddEvent(pEvent);
// 	m_CleanUpEvents.add(pEvent);
}

void GEventManager::MakeTheEventShelf() const
{
// 	if(!m_pHardEventShelf) {
// 		m_pHardEventShelf = new GEventShelf(0);
// 		m_CleanUpEvents.add(m_pHardEventShelf);
// 	}
}

QList<QString> GEventManager::RegisteredEventTypes() const
{
	std::vector<QString> ids = EventManagerInstance()->RegisteredIds();
	QList<QString> typlist;
	for(int i = 0; i < (int)ids.size(); i++) {
		typlist.append(ids[i]);
	}
	return typlist;
}

GEventNode* GEventManager::CreateNewEvent( QString className, QString uniqueIdentifierName, QObject *parent ) const
{
	return EventManagerInstance()->CreateObject( className, uniqueIdentifierName, parent);
}

GEventNode* GEventManager::CreateNewProgEvent( QString className, QObject *parent ) const
{
	// warn if not in RegisteredProgEvents() to prevent using this function on an hardware device.
	// actually it warns only if the className is a hardware device class name to. (so that it doesn't warn for nothing)
	if(RegisteredProgEvents().contains(className))
		return EventManagerInstance()->CreateObject( className, "" /*has to be "" so that the ID is generated by the device*/, parent);
	else if(RegisteredEventTypes().contains(className))
		qWarning("The device specified seems to be a hardware device, NOT a GProgEvent. 4911647");
	return 0;
}

/////////////////////////////////////////////////////////////////////
/*!
Note that this overload will actually try to CreateNewProgEvent() if theMimeData contains the name of such a class.
Note also that in such a case, the created object has a parent set to 0.
\return: GEventNode* : pointer to the GEventNode or created GProgEvent object. 0 if no match.
\param:  const QMimeData * theMimeData : from e.g. a DropEvent. It must hasFormat("LabExe/device.single");
*////////////////////////////////////////////////////////////////////
GEventNode* GEventManager::GetEvent( const QMimeData* theMimeData ) const
{
	// extrapolation from qt help: "Using Drag and Drop with Item Views"
	if(!theMimeData)
		return 0;
	if(!theMimeData->hasFormat("LabExe/device.single")) 
		return 0;
	QByteArray encodedData = theMimeData->data("LabExe/device.single");
	QDataStream devStream(&encodedData, QIODevice::ReadOnly);
	if(devStream.atEnd()) 
		return 0;	
	QString devStrIDorClass;
	devStream >> devStrIDorClass;

	GEventNode* pTheEvent = EventManagerInstance()->GetEvent(devStrIDorClass);
	// if there is no return, maybe we can try the CreateNewProgEvent(), just in case the data were from a drop of a GProgEvent.
	if(!pTheEvent)
		pTheEvent = CreateNewProgEvent(devStrIDorClass, 0);
	// we return the result, which is 0 if nothing worked.
	return pTheEvent;
}

void GEventManager::LoadEventPlugins()
{
// 	QStringList pluginFileNames;
// 	// code taken from the plug and paint Qt example !
// 	QDir pluginsDir = QDir(qApp->applicationDirPath());
//     qDebug() << pluginsDir;
// 
// #if defined(Q_OS_WIN)
//  		pluginsDir.cdUp();
// #elif defined(Q_OS_MAC)
//     if (pluginsDir.dirName() == "MacOS") {
// 	   pluginsDir.cdUp();
//     }
// #endif
//     qDebug()<<pluginsDir;
// 
// 	pluginsDir.cd("plugins");
// 	qDebug() << "Loading plugins from: " << pluginsDir.path();
// 
// 	// for the folder and each sub-folders in the plugin directory
// 	foreach(QString dirName, pluginsDir.entryList(QDir::AllDirs | QDir::NoDotDot)) {
// 		QDir deviceDir(pluginsDir);
// 		deviceDir.cd(dirName);
// 		// for each file in the folder
// 		foreach(QString fileName, deviceDir.entryList(QDir::Files)) {
// 			qDebug() << "trying to load " << fileName;
// 			QPluginLoader loader(deviceDir.absoluteFilePath(fileName), this);
// 			bool didLoad = loader.isLoaded();
// 			if(!didLoad) {
// 
// 			}
// 			QObject *plugin = loader.instance();
// 			GEventPlugin* pEventPlugin = qobject_cast<GEventPlugin*>(plugin);
// 			// if there is a pEventPlugin, we register it with the device manager.
// 			if(pEventPlugin) {
// 				m_CleanUpEvents.add(pEventPlugin);
// 				pluginFileNames += fileName;
// 				pEventPlugin->RegisterEventClassInEventManager();
// 			}
// 		}
// 	}
}

void GEventManager::Add( GEventNode* pEvent )
{
	if(!pEvent)
		return;
	insert(pEvent->UniqueSystemID(), pEvent);
}
