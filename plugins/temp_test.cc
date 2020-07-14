// -*- C++ -*-
//
// Package:    StuffProd/temp_test
// Class:      temp_test
// 
/**\class temp_test temp_test.cc StuffProd/temp_testr/plugins/temp_test.cc
 Description: [one line class summary]
 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Shravan Sunil Chaudhary
//         Created:  Sun, 12 Jul 2020 22:28:54 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/StreamID.h"
#include "StuffProducer/MyStuff/interface/trial1.h"
#include <vector>

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Utilities/interface/StreamID.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"

#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/TrackerGeometryBuilder/interface/StripGeomDetUnit.h"

#include "Calibration/IsolatedParticles/interface/DetIdFromEtaPhi.h"

#include "DQM/HcalCommon/interface/Constants.h"

#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h" // reco::PhotonCollection defined here
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHitFwd.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
using namespace std;
#include <iostream>
using pat::PhotonCollection;
using pat::PhotonRef;
//
// class declaration
//

class temp_test : public edm::stream::EDProducer<> {
   public:
      explicit temp_test(const edm::ParameterSet&);
      ~temp_test();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginStream(edm::StreamID) override;
      virtual void produce(edm::Event&, const edm::EventSetup&) override;
      virtual void endStream() override;

      
      edm::EDGetTokenT<EcalRecHitCollection> EBRecHitCollectionT_; 
      edm::EDGetTokenT<PhotonCollection> photonCollectionT_;
      edm::EDGetTokenT<int> integer_;
      edm::EDGetTokenT<trial1> value_;
      edm::EDGetTokenT<SampleCollection> vecvalues_;
      edm::EDGetTokenT<float> tempgenParticles_;
      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//


//
// static data member definitions
//

//
// constructors and destructor
//
temp_test::temp_test(const edm::ParameterSet& iConfig)
{
   //register your products
/* Examples
   produces<ExampleData2>();
   //if do put with a label
   produces<ExampleData2>("label");
 
   //if you want to put into the Run
   produces<ExampleData2,InRun>();
*/
   //now do what ever other initialization is needed
  std::cout<<"Start"<<std::endl;
  EBRecHitCollectionT_    = consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("reducedEBRecHitCollection"));
  photonCollectionT_ = consumes<PhotonCollection>(iConfig.getParameter<edm::InputTag>("photonCollection"));
  std::cout<<"Stage 1"<<std::endl;
  integer_ = consumes<int>(iConfig.getParameter<edm::InputTag>("integer_"));
  std::cout<<"Stage 2"<<std::endl;
  value_ = consumes<trial1>(iConfig.getParameter<edm::InputTag>("value_"));
  std::cout<<"Stage 3"<<std::endl;
  vecvalues_ = consumes<SampleCollection>(iConfig.getParameter<edm::InputTag>("vecvalues_"));
  std::cout<<"Stage 4"<<std::endl;
  tempgenParticles_ = consumes<float>(iConfig.getParameter<edm::InputTag>("tempgenParticles_"));
  std::cout<<"Stage 5"<<std::endl;
}


temp_test::~temp_test()
{
 
   // do anything here that needs to be done at destruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
temp_test::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
/* This is an event example
   //Read 'ExampleData' from the Event
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
   //Use the ExampleData to create an ExampleData2 which 
   // is put into the Event
   iEvent.put(std::make_unique<ExampleData2>(*pIn));
*/

/* this is an EventSetup example
   //Read SetupData from the SetupRecord in the EventSetup
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
*/
 
 edm::Handle<EcalRecHitCollection> EBRecHitsH_;
 iEvent.getByToken( EBRecHitCollectionT_, EBRecHitsH_);
 edm::Handle<int> intstore_;
 iEvent.getByToken( integer_, intstore_ );
 std::cout<<*intstore_<<std::endl;
 edm::Handle<trial1> valstore_;
 iEvent.getByToken( value_, valstore_ );
 //std::cout<<*valstore_<<std::endl;
 edm::Handle<SampleCollection> vecstore_;
 iEvent.getByToken( vecvalues_, vecstore_ );
 //std::cout<<intstore_<<std::endl;
 edm::Handle<float> floatstore_;
 iEvent.getByToken( tempgenParticles_, floatstore_ );
 std::cout<<*floatstore_<<std::endl;
 
 std::cout<<"All Done."<<std::endl;
}

// ------------ method called once each stream before processing any runs, lumis or events  ------------
void
temp_test::beginStream(edm::StreamID)
{
}

// ------------ method called once each stream after processing all runs, lumis and events  ------------
void
temp_test::endStream() {
}

// ------------ method called when starting to processes a run  ------------
/*
void
temp_test::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
void
temp_test::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
void
temp_test::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
void
temp_test::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
temp_test::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(temp_test);
