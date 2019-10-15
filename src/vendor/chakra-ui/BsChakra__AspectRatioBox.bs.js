// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");
var BsChakra__Types$Ext = require("./BsChakra__Types.bs.js");

function makeProps(maxWidth) {
  var arg = BsChakra__Types$Ext.extractProps(maxWidth, (function (v) {
          return v;
        }));
  return (function (param) {
      return (function (param$1) {
          return (function (param$2, param$3) {
              var param$4 = param$1;
              var param$5 = arg;
              var param$6 = param$2;
              var param$7 = param$3;
              var prim = param;
              var prim$1 = param$4;
              var prim$2 = param$5;
              var prim$3 = param$6;
              var tmp = {
                children: prim
              };
              if (prim$1 !== undefined) {
                tmp.ratio = Caml_option.valFromOption(prim$1);
              }
              if (prim$2 !== undefined) {
                tmp.maxWidth = Caml_option.valFromOption(prim$2);
              }
              if (prim$3 !== undefined) {
                tmp.key = Caml_option.valFromOption(prim$3);
              }
              return tmp;
            });
        });
    });
}

exports.makeProps = makeProps;
/* No side effect */
