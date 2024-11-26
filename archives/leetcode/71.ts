export function simplifyPath(path: string): string {
  const pathDirs = path.split("/").filter((dir) => dir.length > 0);
  // console.log('pathDirs:', pathDirs);
  const ans: string[] = [];
  for (let i = 0; i < pathDirs.length; i++) {
    const dir = pathDirs[i];
    if (dir === ".") {
    } else if (dir === "..") {
      ans.pop();
    } else {
      ans.push(dir);
    }
  }

  return "/" + ans.join("/");
}
