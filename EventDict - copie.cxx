// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME EventDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "Event.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_Event(void *p = 0);
   static void *newArray_Event(Long_t size, void *p);
   static void delete_Event(void *p);
   static void deleteArray_Event(void *p);
   static void destruct_Event(void *p);
   static void streamer_Event(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Event*)
   {
      ::Event *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Event >(0);
      static ::ROOT::TGenericClassInfo
         instance("Event", ::Event::Class_Version(), "Event.h", 19,
                  typeid(::Event), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Event::Dictionary, isa_proxy, 16,
                  sizeof(::Event) );
      instance.SetNew(&new_Event);
      instance.SetNewArray(&newArray_Event);
      instance.SetDelete(&delete_Event);
      instance.SetDeleteArray(&deleteArray_Event);
      instance.SetDestructor(&destruct_Event);
      instance.SetStreamerFunc(&streamer_Event);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Event*)
   {
      return GenerateInitInstanceLocal((::Event*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Event*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Event::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Event::Class_Name()
{
   return "Event";
}

//______________________________________________________________________________
const char *Event::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Event*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Event::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Event*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Event::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Event*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Event::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Event*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Event::Streamer(TBuffer &R__b)
{
   // Stream an object of class Event.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fiEvent;
      R__b >> feTrue;
      R__b >> feReco;
      R__b >> feRecoBias;
      R__b >> x_impact;
      R__b >> y_impact;
      {
         map<CellAddress,CalCell> &R__stl =  filled_cells;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class CellAddress));
         if (R__tcl1==0) {
            Error("filled_cells streamer","Missing the TClass object for class CellAddress!");
            return;
         }
         TClass *R__tcl2 = TBuffer::GetClass(typeid(class CalCell));
         if (R__tcl2==0) {
            Error("filled_cells streamer","Missing the TClass object for class CalCell!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         for (R__i = 0; R__i < R__n; R__i++) {
            CellAddress R__t;
            R__b.StreamObject(&R__t,R__tcl1);
            CalCell R__t2;
            R__b.StreamObject(&R__t2,R__tcl2);
            typedef class CellAddress Value_t;
            std::pair<Value_t const, class CalCell > R__t3(R__t,R__t2);
            R__stl.insert(R__t3);
         }
      }
      R__b >> hist;
      R__b.CheckByteCount(R__s, R__c, Event::IsA());
   } else {
      R__c = R__b.WriteVersion(Event::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fiEvent;
      R__b << feTrue;
      R__b << feReco;
      R__b << feRecoBias;
      R__b << x_impact;
      R__b << y_impact;
      {
         map<CellAddress,CalCell> &R__stl =  filled_cells;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class CellAddress));
         if (R__tcl1==0) {
            Error("filled_cells streamer","Missing the TClass object for class CellAddress!");
            return;
         }
         TClass *R__tcl2 = TBuffer::GetClass(typeid(class CalCell));
         if (R__tcl2==0) {
            Error("filled_cellsstreamer","Missing the TClass object for class CalCell!");
            return;
         }
            map<CellAddress,CalCell>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b.StreamObject((CellAddress*)&((*R__k).first ),R__tcl1);
            R__b.StreamObject((CalCell*)&((*R__k).second),R__tcl2);
            }
         }
      }
      R__b << (TObject*)hist;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Event(void *p) {
      return  p ? new(p) ::Event : new ::Event;
   }
   static void *newArray_Event(Long_t nElements, void *p) {
      return p ? new(p) ::Event[nElements] : new ::Event[nElements];
   }
   // Wrapper around operator delete
   static void delete_Event(void *p) {
      delete ((::Event*)p);
   }
   static void deleteArray_Event(void *p) {
      delete [] ((::Event*)p);
   }
   static void destruct_Event(void *p) {
      typedef ::Event current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_Event(TBuffer &buf, void *obj) {
      ((::Event*)obj)->::Event::Streamer(buf);
   }
} // end of namespace ROOT for class ::Event

namespace ROOT {
   static TClass *maplECellAddresscOCalCellgR_Dictionary();
   static void maplECellAddresscOCalCellgR_TClassManip(TClass*);
   static void *new_maplECellAddresscOCalCellgR(void *p = 0);
   static void *newArray_maplECellAddresscOCalCellgR(Long_t size, void *p);
   static void delete_maplECellAddresscOCalCellgR(void *p);
   static void deleteArray_maplECellAddresscOCalCellgR(void *p);
   static void destruct_maplECellAddresscOCalCellgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<CellAddress,CalCell>*)
   {
      map<CellAddress,CalCell> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<CellAddress,CalCell>));
      static ::ROOT::TGenericClassInfo
         instance("map<CellAddress,CalCell>", -2, "map", 824,
                  typeid(map<CellAddress,CalCell>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplECellAddresscOCalCellgR_Dictionary, isa_proxy, 0,
                  sizeof(map<CellAddress,CalCell>) );
      instance.SetNew(&new_maplECellAddresscOCalCellgR);
      instance.SetNewArray(&newArray_maplECellAddresscOCalCellgR);
      instance.SetDelete(&delete_maplECellAddresscOCalCellgR);
      instance.SetDeleteArray(&deleteArray_maplECellAddresscOCalCellgR);
      instance.SetDestructor(&destruct_maplECellAddresscOCalCellgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<CellAddress,CalCell> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<CellAddress,CalCell>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplECellAddresscOCalCellgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<CellAddress,CalCell>*)0x0)->GetClass();
      maplECellAddresscOCalCellgR_TClassManip(theClass);
   return theClass;
   }

   static void maplECellAddresscOCalCellgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplECellAddresscOCalCellgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<CellAddress,CalCell> : new map<CellAddress,CalCell>;
   }
   static void *newArray_maplECellAddresscOCalCellgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<CellAddress,CalCell>[nElements] : new map<CellAddress,CalCell>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplECellAddresscOCalCellgR(void *p) {
      delete ((map<CellAddress,CalCell>*)p);
   }
   static void deleteArray_maplECellAddresscOCalCellgR(void *p) {
      delete [] ((map<CellAddress,CalCell>*)p);
   }
   static void destruct_maplECellAddresscOCalCellgR(void *p) {
      typedef map<CellAddress,CalCell> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<CellAddress,CalCell>

namespace {
  void TriggerDictionaryInitialization_EventDict_Impl() {
    static const char* headers[] = {
"Event.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/Cellar/root6/6.08.02/include/root",
"/Users/ENS-08/Desktop/CaloSimulation/StageAlgoCPMCaloSkel/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "EventDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Event structure)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$Event.h")))  Event;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "EventDict dictionary payload"
#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#define _BACKWARD_BACKWARD_WARNING_H
#include "Event.h"
#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Event", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("EventDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_EventDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_EventDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_EventDict() {
  TriggerDictionaryInitialization_EventDict_Impl();
}
