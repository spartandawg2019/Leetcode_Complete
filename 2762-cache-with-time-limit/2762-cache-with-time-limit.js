class TimeLimitedCache {
  constructor() {
    this.cache = new Map();
  }

  set(key, value, duration) {
    const expirationTime = Date.now() + duration;

    if (this.cache.has(key) && this.cache.get(key).expirationTime > Date.now()) {
      this.cache.set(key, { value, expirationTime });
      return true;
    }

    this.cache.set(key, { value, expirationTime });
    return false;
  }

  get(key) {
    const cachedData = this.cache.get(key);
    if (!cachedData || cachedData.expirationTime < Date.now()) {
      return -1;
    }
    return cachedData.value;
  }

  count() {
    let count = 0;
    for (const [key, cachedData] of this.cache.entries()) {
      if (cachedData.expirationTime >= Date.now()) {
        count++;
      } else {
        this.cache.delete(key);
      }
    }
    return count;
  }
}

// Example usage
const cache = new TimeLimitedCache();
console.log(cache.set(1, 42, 100)); // false
console.log(cache.get(1)); // 42
console.log(cache.count()); // 1
