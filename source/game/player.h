#pragma once

#include "IPlayer.h"

namespace game
{
   class CPlayer : public IPlayer
   {
   public:
      CPlayer();
      virtual objects::IObject::Ptr selectObject( objects::TObjectList& ) override final;

      virtual bool isNeedSelect() override final;
      virtual int getIndex() override final;
      virtual objects::IObject::ConstPtr getObject() override final;
      virtual const objects::TObjectList& getFullList() override final;

   private:
      int eventHandler( int key );
      objects::TObjectList list;
      objects::TObjectList::iterator listIterator;
      int index;
      bool needSelect;
   };
} 
