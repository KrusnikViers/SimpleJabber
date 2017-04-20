cmake_minimum_required(VERSION 3.2.2)
cmake_policy(SET CMP0020 NEW)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0043 NEW)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_REQUIRED TRUE)
find_package(Qt5Network REQUIRED)
find_package(Qt5Xml REQUIRED)

# SHARED-THIRD-PARTY
add_custom_target(shared-third-party)
add_custom_command(TARGET shared-third-party POST_BUILD
                   COMMENT "Shared libraries added to ${PROJECT_BINARY_DIR}"
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                           ${CMAKE_CURRENT_SOURCE_DIR}/shared ${PROJECT_BINARY_DIR})

# QXMPP-STATIC
project(qxmpp-static C CXX)
set(QXMPP_VERSION 0.9.3)
include_directories(qxmpp/src/base)
include_directories(qxmpp/src/client)
set (QXMPP_SRC
    qxmpp/src/base/QXmppArchiveIq.cpp
    qxmpp/src/base/QXmppArchiveIq.h
    qxmpp/src/base/QXmppBindIq.cpp
    qxmpp/src/base/QXmppBindIq.h
    qxmpp/src/base/QXmppBookmarkSet.cpp
    qxmpp/src/base/QXmppBookmarkSet.h
    qxmpp/src/base/QXmppByteStreamIq.cpp
    qxmpp/src/base/QXmppByteStreamIq.h
    qxmpp/src/base/QXmppCodec.cpp
    qxmpp/src/base/QXmppCodec_p.h
    qxmpp/src/base/QXmppConstants.cpp
    qxmpp/src/base/QXmppConstants_p.h
    qxmpp/src/base/QXmppDataForm.cpp
    qxmpp/src/base/QXmppDataForm.h
    qxmpp/src/base/QXmppDiscoveryIq.cpp
    qxmpp/src/base/QXmppDiscoveryIq.h
    qxmpp/src/base/QXmppElement.cpp
    qxmpp/src/base/QXmppElement.h
    qxmpp/src/base/QXmppEntityTimeIq.cpp
    qxmpp/src/base/QXmppEntityTimeIq.h
    qxmpp/src/base/QXmppGlobal.cpp
    qxmpp/src/base/QXmppGlobal.h
    qxmpp/src/base/QXmppIbbIq.cpp
    qxmpp/src/base/QXmppIbbIq.h
    qxmpp/src/base/QXmppIq.cpp
    qxmpp/src/base/QXmppIq.h
    qxmpp/src/base/QXmppJingleIq.cpp
    qxmpp/src/base/QXmppJingleIq.h
    qxmpp/src/base/QXmppLogger.cpp
    qxmpp/src/base/QXmppLogger.h
    qxmpp/src/base/QXmppMessage.cpp
    qxmpp/src/base/QXmppMessage.h
    qxmpp/src/base/QXmppMucIq.cpp
    qxmpp/src/base/QXmppMucIq.h
    qxmpp/src/base/QXmppNonSASLAuth.cpp
    qxmpp/src/base/QXmppNonSASLAuth.h
    qxmpp/src/base/QXmppPingIq.cpp
    qxmpp/src/base/QXmppPingIq.h
    qxmpp/src/base/QXmppPresence.cpp
    qxmpp/src/base/QXmppPresence.h
    qxmpp/src/base/QXmppPubSubIq.cpp
    qxmpp/src/base/QXmppPubSubIq.h
    qxmpp/src/base/QXmppRegisterIq.cpp
    qxmpp/src/base/QXmppRegisterIq.h
    qxmpp/src/base/QXmppResultSet.cpp
    qxmpp/src/base/QXmppResultSet.h
    qxmpp/src/base/QXmppRosterIq.cpp
    qxmpp/src/base/QXmppRosterIq.h
    qxmpp/src/base/QXmppRpcIq.cpp
    qxmpp/src/base/QXmppRpcIq.h
    qxmpp/src/base/QXmppRtcpPacket.cpp
    qxmpp/src/base/QXmppRtcpPacket.h
    qxmpp/src/base/QXmppRtpChannel.cpp
    qxmpp/src/base/QXmppRtpChannel.h
    qxmpp/src/base/QXmppRtpPacket.cpp
    qxmpp/src/base/QXmppRtpPacket.h
    qxmpp/src/base/QXmppSasl.cpp
    qxmpp/src/base/QXmppSasl_p.h
    qxmpp/src/base/QXmppSessionIq.cpp
    qxmpp/src/base/QXmppSessionIq.h
    qxmpp/src/base/QXmppSocks.cpp
    qxmpp/src/base/QXmppSocks.h
    qxmpp/src/base/QXmppStanza.cpp
    qxmpp/src/base/QXmppStanza.h
    qxmpp/src/base/QXmppStanza_p.h
    qxmpp/src/base/QXmppStream.cpp
    qxmpp/src/base/QXmppStream.h
    qxmpp/src/base/QXmppStreamFeatures.cpp
    qxmpp/src/base/QXmppStreamFeatures.h
    qxmpp/src/base/QXmppStreamInitiationIq.cpp
    qxmpp/src/base/QXmppStreamInitiationIq_p.h
    qxmpp/src/base/QXmppStreamManagement.cpp
    qxmpp/src/base/QXmppStun.cpp
    qxmpp/src/base/QXmppStun.h
    qxmpp/src/base/QXmppStun_p.h
    qxmpp/src/base/QXmppUtils.cpp
    qxmpp/src/base/QXmppUtils.h
    qxmpp/src/base/QXmppVCardIq.cpp
    qxmpp/src/base/QXmppVCardIq.h
    qxmpp/src/base/QXmppVersionIq.cpp
    qxmpp/src/base/QXmppVersionIq.h
    qxmpp/src/client/QXmppArchiveManager.cpp
    qxmpp/src/client/QXmppArchiveManager.h
    qxmpp/src/client/QXmppBookmarkManager.cpp
    qxmpp/src/client/QXmppBookmarkManager.h
    qxmpp/src/client/QXmppCallManager.cpp
    qxmpp/src/client/QXmppCallManager.h
    qxmpp/src/client/QXmppCarbonManager.cpp
    qxmpp/src/client/QXmppCarbonManager.h
    qxmpp/src/client/QXmppClient.cpp
    qxmpp/src/client/QXmppClient.h
    qxmpp/src/client/QXmppClientExtension.cpp
    qxmpp/src/client/QXmppClientExtension.h
    qxmpp/src/client/QXmppConfiguration.cpp
    qxmpp/src/client/QXmppConfiguration.h
    qxmpp/src/client/QXmppDiscoveryManager.cpp
    qxmpp/src/client/QXmppDiscoveryManager.h
    qxmpp/src/client/QXmppEntityTimeManager.cpp
    qxmpp/src/client/QXmppEntityTimeManager.h
    qxmpp/src/client/QXmppInvokable.cpp
    qxmpp/src/client/QXmppInvokable.h
    qxmpp/src/client/QXmppMessageReceiptManager.cpp
    qxmpp/src/client/QXmppMessageReceiptManager.h
    qxmpp/src/client/QXmppMucManager.cpp
    qxmpp/src/client/QXmppMucManager.h
    qxmpp/src/client/QXmppOutgoingClient.cpp
    qxmpp/src/client/QXmppOutgoingClient.h
    qxmpp/src/client/QXmppRemoteMethod.cpp
    qxmpp/src/client/QXmppRemoteMethod.h
    qxmpp/src/client/QXmppRosterManager.cpp
    qxmpp/src/client/QXmppRosterManager.h
    qxmpp/src/client/QXmppRpcManager.cpp
    qxmpp/src/client/QXmppRpcManager.h
    qxmpp/src/client/QXmppTransferManager.cpp
    qxmpp/src/client/QXmppTransferManager.h
    qxmpp/src/client/QXmppTransferManager_p.h
    qxmpp/src/client/QXmppVCardManager.cpp
    qxmpp/src/client/QXmppVCardManager.h
    qxmpp/src/client/QXmppVersionManager.cpp
    qxmpp/src/client/QXmppVersionManager.h)
add_library(qxmpp-static STATIC ${QXMPP_SRC})
add_definitions(-DQXMPP_STATIC)
qt5_use_modules(qxmpp-static Network Xml)
