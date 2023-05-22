var jsonStringify = function(object) {
  if (object === null) {
    return 'null';
  } else if (typeof object === 'string') {
    return '"' + object + '"';
  } else if (typeof object === 'number' || typeof object === 'boolean') {
    return object.toString();
  } else if (Array.isArray(object)) {
    var arr = [];
    for (var i = 0; i < object.length; i++) {
      arr.push(jsonStringify(object[i]));
    }
    return '[' + arr.join(',') + ']';
  } else {
    var obj = [];
    var keys = Object.keys(object);
    for (var i = 0; i < keys.length; i++) {
      var key = keys[i];
      obj.push('"' + key + '":' + jsonStringify(object[key]));
    }
    return '{' + obj.join(',') + '}';
  }
};
