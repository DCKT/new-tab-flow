// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");
var BsChakra__Types$Ext = require("./BsChakra__Types.bs.js");

function makeProps(textAlign, width, height) {
  var arg = BsChakra__Types$Ext.extractProps(textAlign, (function (v) {
          return v;
        }));
  var arg$1 = BsChakra__Types$Ext.extractProps(height, (function (v) {
          return v;
        }));
  var arg$2 = BsChakra__Types$Ext.extractProps(width, (function (v) {
          return v;
        }));
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5) {
          return (function (param$6, param$7) {
              var param$8 = param$1;
              var param$9 = param$2;
              var param$10 = param$3;
              var param$11 = param$4;
              var param$12 = param$5;
              var param$13 = arg;
              var param$14 = arg$1;
              var param$15 = arg$2;
              var param$16 = param$6;
              var param$17 = param$7;
              var prim = param;
              var prim$1 = param$8;
              var prim$2 = param$9;
              var prim$3 = param$10;
              var prim$4 = param$11;
              var prim$5 = param$12;
              var prim$6 = param$13;
              var prim$7 = param$14;
              var prim$8 = param$15;
              var prim$9 = param$16;
              var tmp = {
                children: prim
              };
              if (prim$1 !== undefined) {
                tmp.status = (function () {
                      switch (Caml_option.valFromOption(prim$1)) {
                        case -215364664 : 
                            return "error";
                        case 944645571 : 
                            return "success";
                        case 164354652 : 
                            return "warning";
                        case -977586066 : 
                            return "info";
                        
                      }
                    })();
              }
              if (prim$2 !== undefined) {
                tmp.variant = (function () {
                      switch (Caml_option.valFromOption(prim$2)) {
                        case 436972141 : 
                            return "subtle";
                        case 974605489 : 
                            return "left-accent";
                        case -750646849 : 
                            return "top-accent";
                        
                      }
                    })();
              }
              if (prim$3 !== undefined) {
                tmp.direction = (function () {
                      switch (Caml_option.valFromOption(prim$3)) {
                        case 5693978 : 
                            return "row";
                        case -963948842 : 
                            return "column";
                        
                      }
                    })();
              }
              if (prim$4 !== undefined) {
                tmp.justifyContent = (function () {
                      switch (Caml_option.valFromOption(prim$4)) {
                        case 662439529 : 
                            return "flex-start";
                        case 98248149 : 
                            return "center";
                        case 924268066 : 
                            return "flex-end";
                        case -485895757 : 
                            return "space-around";
                        case 516682146 : 
                            return "space-between";
                        
                      }
                    })();
              }
              if (prim$5 !== undefined) {
                tmp.alignItems = (function () {
                      switch (Caml_option.valFromOption(prim$5)) {
                        case 662439529 : 
                            return "flex-start";
                        case 98248149 : 
                            return "center";
                        case 924268066 : 
                            return "flex-end";
                        case -485895757 : 
                            return "space-around";
                        case 516682146 : 
                            return "space-between";
                        
                      }
                    })();
              }
              if (prim$6 !== undefined) {
                tmp.textAlign = Caml_option.valFromOption(prim$6);
              }
              if (prim$7 !== undefined) {
                tmp.height = Caml_option.valFromOption(prim$7);
              }
              if (prim$8 !== undefined) {
                tmp.width = Caml_option.valFromOption(prim$8);
              }
              if (prim$9 !== undefined) {
                tmp.key = Caml_option.valFromOption(prim$9);
              }
              return tmp;
            });
        });
    });
}

exports.makeProps = makeProps;
/* No side effect */
