// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");
var BsChakra__Types$Ext = require("./BsChakra__Types.bs.js");

function makeProps(spacing) {
  var arg = BsChakra__Types$Ext.extractSpaceProps(spacing);
  return (function (param) {
      return (function (param$1, param$2) {
          var prim = param;
          var prim$1 = arg;
          var prim$2 = param$1;
          var tmp = {
            children: prim,
            spacing: prim$1
          };
          if (prim$2 !== undefined) {
            tmp.key = Caml_option.valFromOption(prim$2);
          }
          return tmp;
        });
    });
}

exports.makeProps = makeProps;
/* No side effect */