#ifndef GEventNode_H
#define GEventNode_H
#include "labexesequencer_global.h"

#include <QStandardItem>
#include <QGraphicsLineItem>
#include "ToolBox/GSerializable.h"
#include "GEventManager.h"

// TRY BASALT
#include "../../../MapExe/src/agent.h"

class GParam;

//! Returns the device manager
LABEXESEQUENCER_EXPORT GEventManager* EventManagerInstance(); 
////! Loads the plugins in the Agent manager
//LABEXE_EXPORT void LoadPluginsInDeviceManager(); 
////! Returns the device whose uniqueIdentifierName matches in the device manager, 0 otherwise.
//LABEXE_EXPORT GDevice* GetDeviceFromDeviceManager(QString uniqueIdentifierName); 
////! Adds the device to the hard device shelf.
//LABEXE_EXPORT void AddToDeviceShelf(GDevice* pDevice); 
////! Registers the device into the device manager.
//LABEXE_EXPORT bool RegisterHardDeviceInManager(const QString & className, GDevice*(deviceCreator)(QString, QObject*));
////! Registers the prog device into the device manager.
//LABEXE_EXPORT bool RegisterProgDeviceInManager(const QString & className, GDevice*(deviceCreator)(QString, QObject*)); 


class GEventNode : public GAgent, protected QGraphicsLineItem
{
	Q_OBJECT

public:
	GEventNode(GEventNode* pParentNode);
	~GEventNode();


	//! Implemented
	virtual bool InjectInitializationData(const QVariantList & theDataList) {return false;}
	//! Implemented
	virtual QVariantList ProvideInitializationData() {return QVariantList();}
	//! Implemented
	virtual QGraphicsItem* NewContentItem(GAgentWrapitem* pParentItem) {return new QGraphicsLineItem(0.0, 0.0, 0.0, 100.0);}

	//! Re-implemented to add the new ID in the EventManagerInstance(). It doesn't remove the previous one.
	void Event_UniqueSystemIDChanged(const QString & newSystemID);
	

	void SetParent(GEventNode* pParent) {
		setParent(pParent);
		setParentItem(pParent);
	}
	GEventNode* ParentNode() const {return static_cast<GEventNode*>(parentItem());}
	const QList<GEventNode*> ChildNodes() const;

	//! Inserts the node as a child of this event at the position atPos. If atPos is not specified, the node is appended at the end.
	void InsertChildEvent(GEventNode* node, int atPos = -1);

	virtual QVariant data() const {return "data::GEventNode";}
	//! adjust the vertical size/position
	virtual void UpdateVerticalPosition();

public:
	//! Reimplemented.
	virtual void PopulateSettings(QSettings& inQsettings);
	//! Reimplemented.
	virtual void InterpretSettings(QSettings& fromQsettings);
	//! Returns the child of this event that are GParam`s
	QList<GParam*> ChildParams() const;


protected:
	//! reimplemented from QGraphicsItem to inform of changes in the item properties. Adequate measures can be taken e.g. for maintaing vertical position.
	virtual	QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:

	friend class GEvScene;
	
};

#endif // GEventNode_H
