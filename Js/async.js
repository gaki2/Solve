import axios from "axios";

function getUserInfo(userIndex) {
  const promise = axios.get(
    `https://jsonplaceholder.typicode.com/todos/${userIndex}`
  );

  return promise;
}

async function main() {
  let user = await getUserInfo(1).then((res) => res.data);
  console.log(user);
}

// getUserInfo(1);

main();
