import qbs.base 1.0
import qbs.fileinfo 1.0 as FileInfo

Project {
    property string qutim_version_major: '0'
    property string qutim_version_minor: '3'
    property string qutim_version_release: '1'
    property string qutim_version_patch: '1'
    property string qutim_version: qutim_version_major + '.' + qutim_version_minor + '.' + qutim_version_release + '.' + qutim_version_patch
    property bool declarativeUi: false
    property var additionalCppDefines: []
    //property string shareDir: {
    //}

    property bool singleProfile: true

    moduleSearchPaths: [ "modules", "qbs/modules" ]

    // references: [ "core/*.qbs", "protocols/*.qbs", "plugins/*.qbs" ]
    // recursive: true

    references: [
        "translations/translations.qbs",
        "core/3rdparty/k8json.qbs",
        "core/3rdparty/qxdg.qbs",
        //"core/3rdparty/flowlayout.qbs",
        //"core/3rdparty/slidingstackedwidget.qbs",
        "core/3rdparty/qxt.qbs",
        "core/3rdparty/qtdwm.qbs",
        "core/3rdparty/qtsolutions.qbs",
        "core/artwork.qbs",
        "core/libqutim.qbs",
        "core/libqutim-headers.qbs",
        "core/qutim.qbs",
        "core/src/corelayers/accountcreator/accountcreator.qbs",
        "core/src/corelayers/addcontactdlg/addcontactdlg.qbs",
        "core/src/corelayers/adiumchat/adiumchat.qbs",
        "core/src/corelayers/adiumchat/adiumchat-headers.qbs",
        "core/src/corelayers/adiumchat/chatfactories/textchat/textchat.qbs",
        "core/src/corelayers/adiumchat/chatforms/stackedchatform/stackedchatform.qbs",
        "core/src/corelayers/adiumchat/chatforms/tabbedchatform/tabbedchatform.qbs",
        "core/src/corelayers/adiumsrvicons/adiumsrvicons.qbs",
        "core/src/corelayers/authdialog/authdialog.qbs",
        "core/src/corelayers/chatnotificationsbackend/chatnotificationsbackend.qbs",
        "core/src/corelayers/chatspellchecker/chatspellchecker.qbs",
        "core/src/corelayers/comparators/comparators.qbs",
        "core/src/corelayers/contactinfo/contactinfo.qbs",
        "core/src/corelayers/dataformsbackend/dataformsbackend.qbs",
        "core/src/corelayers/emoticonssettings/emoticonssettings.qbs",
        "core/src/corelayers/filetransfer/filetransfer.qbs",
        "core/src/corelayers/filetransfersettings/filetransfersettings.qbs",
        "core/src/corelayers/idledetector/idledetector.qbs",
        "core/src/corelayers/idlestatuschanger/idlestatuschanger.qbs",
        "core/src/corelayers/joinchatdialog/joinchatdialog.qbs",
        "core/src/corelayers/joingroupchatdlg/joingroupchatdlg.qbs",
        "core/src/corelayers/jsonconfig/jsonconfig.qbs",
        "core/src/corelayers/jsonhistory/jsonhistory.qbs",
        "core/src/corelayers/kineticscroller/kineticscroller.qbs",
        "core/src/corelayers/kopeteemoticonsbackend/kopeteemoticonsbackend.qbs",
        "core/src/corelayers/localization/localization.qbs",
        "core/src/corelayers/metacontacts/metacontacts.qbs",
        "core/src/corelayers/migration02x03/migration02x03.qbs",
        "core/src/corelayers/mobileabout/mobileabout.qbs",
        "core/src/corelayers/mobilecontactinfo/mobilecontactinfo.qbs",
        "core/src/corelayers/mobilesettingsdialog/mobilesettingsdialog.qbs",
        "core/src/corelayers/mobilenotificationssettings/mobilenotificationssettings.qbs",
        "core/src/corelayers/nocryptoservice/nocryptoservice.qbs",
        "core/src/corelayers/notificationfilter/notificationfilter.qbs",
        "core/src/corelayers/notificationssettings/notificationssettings.qbs",
        "core/src/corelayers/oldsoundtheme/oldsoundtheme.qbs",
        "core/src/corelayers/password/password.qbs",
        "core/src/corelayers/plistconfig/plistconfig.qbs",
        "core/src/corelayers/proxysettings/proxysettings.qbs",
        "core/src/corelayers/qticons/qticons.qbs",
        "core/src/corelayers/searchdialog/searchdialog.qbs",
        "core/src/corelayers/servicechooser/servicechooser.qbs",
        "core/src/corelayers/sessionhelper/sessionhelper.qbs",
        "core/src/corelayers/shortcutsettings/shortcutsettings.qbs",
        "core/src/corelayers/simpleabout/simpleabout.qbs",
        "core/src/corelayers/simpleactionbox/simpleactionbox.qbs",
        "core/src/corelayers/simpleactions/simpleactions.qbs",
        "core/src/corelayers/simplecontactlist/libqutim-simplecontactlist.qbs",
        "core/src/corelayers/simplecontactlist/models/plaincontactsmodel/plaincontactsmodel.qbs",
        "core/src/corelayers/simplecontactlist/models/separatedcontactsmodel/separatedcontactsmodel.qbs",
        "core/src/corelayers/simplecontactlist/models/treecontactsmodel/treecontactsmodel.qbs",
        "core/src/corelayers/simplecontactlist/simplecontactdelegate/simplecontactdelegate.qbs",
        "core/src/corelayers/simplecontactlist/simplecontactlist.qbs",
        "core/src/corelayers/simplecontactlist/simplecontactlist-headers.qbs",
        "core/src/corelayers/simplecontactlist/widgets/simplecontactlistwidget/simplecontactlistwidget.qbs",
        "core/src/corelayers/simplecontactlist/widgets/torycontactlistwidget/torycontactlistwidget.qbs",
        "core/src/corelayers/simplerosterstorage/simplerosterstorage.qbs",
        "core/src/corelayers/softkeysactionbox/softkeysactionbox.qbs",
        "core/src/corelayers/soundthemeselector/soundthemeselector.qbs",
        "core/src/corelayers/trayicon/trayicon.qbs",
        "core/src/corelayers/xsettingsdialog/xsettingsdialog.qbs",
        "protocols/vkontakte/vreen/src/api.qbs", //vreen
        "protocols/vkontakte/vreen/src/oauth/oauth.qbs",
        "protocols/vkontakte/vkontakte.qbs",
        "protocols/oscar/3rdparty/hmac.qbs",
        "protocols/oscar/oscar.qbs",
        "protocols/oscar/plugins/identify.qbs",
        "protocols/oscar/plugins/xstatus.qbs",
        "protocols/mrim/mrim.qbs",
        "protocols/jabber/jreen/jreen.qbs",
        "protocols/jabber/jabber.qbs",
        "protocols/quetzal/quetzal.qbs",
        "protocols/irc/irc.qbs",
     //   "protocols/astral/astral.qbs",
        "plugins/autoreply/autoreply.qbs",
        "plugins/macintegration/src/maccontactlistwidget/maccontactlistwidget.qbs",
        "plugins/macintegration/src/macdock/macdock.qbs",
        "plugins/macintegration/src/macgrowl/macgrowl.qbs",
        "plugins/macintegration/src/macidle/macidle.qbs",
    //    "plugins/macintegration/src/macnotifications/macnotifications.qbs",
        "plugins/macintegration/src/macspellchecker/macspellchecker.qbs",
        "plugins/adiumwebview/adiumwebview.qbs",
        "plugins/adiumwebview/lib/qutim-adiumwebview.qbs",
        "plugins/aescrypto/aescrypto.qbs",
        "plugins/antiboss/antiboss.qbs",
        "plugins/antispam/antispam.qbs",
        "plugins/aspeller/aspeller.qbs",
        "plugins/awn/awn.qbs",
        "plugins/birthdayreminder/birthdayreminder.qbs",
        "plugins/blogimprover/blogimprover.qbs",
        "plugins/clconf/clconf.qbs",
        "plugins/control/control.qbs",
        "plugins/dbusapi/dbusapi.qbs",
        "plugins/dbusnotifications/dbusnotifications.qbs",
        "plugins/docktile/qtdocktile/qtdocktile.qbs",
        "plugins/docktile/docktile.qbs",
        "plugins/emoedit/emoedit.qbs",
        "plugins/floaties/floaties.qbs",
        "plugins/formula/formula.qbs",
        "plugins/haikunotifications/haikunotifications.qbs",
        "plugins/highlighter/highlighter.qbs",
        "plugins/histman/histman.qbs",
        "plugins/hunspeller/hunspeller.qbs",
        //"plugins/imagepub/imagepub.qbs",
        //"plugins/indicator/indicator.qbs",
        "plugins/kdeintegration/kdeintegration.qbs",
        "plugins/kineticpopups/kineticpopups.qbs",
        "plugins/linuxintegration/linuxintegration.qbs",
        "plugins/logger/logger.qbs",
        // "plugins/maemo5integration/maemo5integration.qbs",
        "plugins/massmessaging/massmessaging.qbs",
        //"plugins/meegointegration/meegointegration.qbs",
        "plugins/mobility/src/bearermanager/bearermanager.qbs",
        "plugins/mobility/src/multimediabackend/multimediabackend.qbs",
        //"plugins/mobility/src/vibrobackend/vibrobackend.qbs",
        "plugins/nowplaying/nowplaying.qbs",
        "plugins/offtherecord/offtherecord.qbs",
        "plugins/oldcontactdelegate/oldcontactdelegate.qbs",
        //"plugins/phononsound/phononsound.qbs",
        "plugins/plugman/plugman.qbs",
        "plugins/qmlchat/qmlchat.qbs",
        //"plugins/qrcicons/qrcicons.qbs",
        "plugins/scriptapi/scriptapi.qbs",
        "plugins/sdlsound/sdlsound.qbs",
        //"plugins/sqlhistory/sqlhistory.qbs",
        //"plugins/symbianintegration/symbianintegration.qbs",
        "plugins/unreadmessageskeeper/unreadmessageskeeper.qbs",
        "plugins/updater/updater.qbs",
        "plugins/urlpreview/urlpreview.qbs",
        "plugins/weather/weather.qbs",
        //"plugins/webhistory/webhistory.qbs",
        //"plugins/winintegration/winintegration.qbs",
        "plugins/yandexnarod/yandexnarod.qbs"
    ]
}

